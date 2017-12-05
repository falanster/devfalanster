<?php // -*- indent-tabs-mode:nil -*-

/**
 * @file
 * DrupalFileCache class that implements DrupalCacheInterface.
 *
 * This file is added to $conf['cache_backends'] array in site's
 * settings.php so that DrupalFileCache class can be the handler for
 * cache bins.
 */

/**
 * Max filename length for cid.
 *
 *  Doesn't include cache bin prefix. Must be at least 34 (see
 * FILECACHE_CID_FILENAME_POS_BEFORE_MD5).
 */
define('FILECACHE_CID_FILENAME_MAX', 200);

/**
 * Cut point between not MD5 encoded and MD5 encoded.
 *
 * 34 is '%_' + 32 hexdigits for 128-bit MD5
 */
define('FILECACHE_CID_FILENAME_POS_BEFORE_MD5', FILECACHE_CID_FILENAME_MAX - 34);

/**
 * Cache bin registry file.
 */
define('FILECACHE_CACHE_BIN_REGISTRY', 'filecache_bins');

define('FILECACHE_QUICKSTART_DIRECTORY', '.ht.filecache.quickstart');

define('FILECACHE_DIRECTORY_MODE', 0700);

define('FILECACHE_FILE_MODE', 0600);

function filecache_default_directory($quickstart = TRUE) {
  $dir = FILECACHE_QUICKSTART_DIRECTORY;
  if (!$quickstart) {
    $dir = str_replace('.quickstart', '', $dir);
  }
  return DRUPAL_ROOT . '/' . conf_path() . '/files/' . $dir;
}
/**
 * Get base File Cache directory.
 */
function filecache_directory($bin = FALSE) {
  $filecache_directory = variable_get('filecache_directory', FALSE);
  if (is_array($filecache_directory)) {
    if (is_string($bin) && array_key_exists($bin, $filecache_directory)) {
      $filecache_directory = $filecache_directory[$bin];
    } else if (array_key_exists('default', $filecache_directory)) {
      $filecache_directory = $filecache_directory['default'];
    }
  }
  if (!is_string($filecache_directory)) {
    $filecache_directory = filecache_default_directory();
  }
  return $filecache_directory;
}

function filecache_is_readdeleteonly() {
  return substr(php_sapi_name(), 0, 3) == "cli" || (extension_loaded('posix') && posix_getuid() == 0);
}

/**
 * Implement unified cache bin prefix as described in https://www.drupal.org/node/1324812
 * 
 * By default, conf_path() is used as prefix after replacing '/' with '_', and adding final '_'.
 * 
 * @global type $conf
 * @return string The prefix, or empty string if there is no prefix;
 */
function get_cache_prefix($bin = FALSE) {
  $prefix = str_replace('/', '_', conf_path()) . '_';
  global $conf;
  if (array_key_exists('cache_prefix', $conf)) {
    $cache_prefix_conf = $conf['cache_prefix'];
    if ($cache_prefix_conf === FALSE || is_string($cache_prefix_conf)) {
      $prefix = $cache_prefix_conf;
    } elseif (is_array($cache_prefix_conf)) {
      if (is_string($bin) && array_key_exists($bin, $cache_prefix_conf)) {
        $prefix = $cache_prefix_conf[$bin];
      } else if (array_key_exists('default', $cache_prefix_conf)) {
        $prefix = $cache_prefix_conf['default'];
      }
    }
  }
  if (is_string($prefix)) {
    return $prefix;
  } else {
    return "";
  }
}
  
function filecache_registry_pathname() {
  return filecache_directory() . '/' . get_cache_prefix() . FILECACHE_CACHE_BIN_REGISTRY;
}

class DrupalFileCache implements DrupalCacheInterface {

  /**
   * Construct DrupalFileCache for specified cache bin.
   *
   * @param $bin
   *   Cache bin name.
   */
  function __construct($bin) {
    $this->bin = $bin;
    $this->directory = filecache_directory($bin) . '/' . get_cache_prefix($bin) . $bin;

    $this->ok = $this->check_filecache_directory();
    $this->truncate_if_needed();
  }

  private function check_filecache_directory() {
    $t = get_t();
    $critical_message = FALSE;
    if (!is_dir($this->directory)) {
      if (!file_exists($this->directory)) {
        if (filecache_is_readdeleteonly()) {
          watchdog('filecache', 'Need to create directory %dir but not running in webserver and permissions of created directory would become wrong',
              array('%dir' => $this->directory), WATCHDOG_NOTICE);
          return FALSE;
        }
        // Directory does not exist. Try to create it.
        if (!mkdir($this->directory, FILECACHE_DIRECTORY_MODE, TRUE)) {
          $critical_message = $t('%dir does not exist and cannot be created. Please check directory permissions.',
              array('%dir' => $this->directory));
        }
      }
      else {
        $critical_message = $t('%dir is not a directory.', array('%dir' => $this->directory));
      }
    }
    elseif (!is_writable($this->directory)) {
      $critical_message = $t('PHP cannot write to directory %dir.', array('%dir' => $this->directory));
    }

    if ($critical_message) {
      watchdog('filecache', $critical_message, array(), WATCHDOG_CRITICAL);
      return FALSE;
    }
    return TRUE;
  }
  
  private function truncate_if_needed() {
    $registry_pathname = filecache_registry_pathname();
    $registry = @unserialize(@file_get_contents($registry_pathname));
    if (!isset($registry) || !is_array($registry))  {
      $registry = array();
    }
    $registry_changed = FALSE;
    $do_truncate = FALSE;
    if (!array_key_exists($this->bin, $registry)) {
      $registry[$this->bin] = NULL;
      $registry_changed = TRUE;
      $do_truncate = TRUE;
    } else {
      // Check all other cache bins in registry
      global $conf;
      foreach ($registry as $filecache_bin => $placeholder) {
        $cache_class_setting = 'cache_class_' . $filecache_bin;
        if (array_key_exists($cache_class_setting, $conf) && $conf[$cache_class_setting] != 'DrupalFileCache') {
          // The cache bin is configured for specified cache class but it is not our cache class.
          unset($registry[$filecache_bin]);
          $registry_changed = TRUE;
        }
      }
    }
    if ($registry_changed) {
      if ($this->ok && !filecache_is_readdeleteonly()) {
        file_put_contents($registry_pathname, serialize($registry));
      }
    }
    if ($do_truncate) {
      $db_cache = new DrupalDatabaseCache($this->bin);
      $db_cache->clear('*', TRUE);

      $this->delete_wildcard('');
    }
  }

  /**
   * Make cache ID usable for file name.
   *
   * @param $cid
   *   Cache ID.
   * @return
   *   String that is derived from $cid and can be used as file name.
   */
  function encode_cid($cid) {
    // Use urlencode(), but turn the
    // encoded ':' and '/' back into ordinary characters since they're used so
    // often. (Especially ':', but '/' is used in cache_menu.)
    // We can't turn them back into their own characters though; both are
    // considered unsafe in filenames. So turn ':' -> '@' and '/' -> '='
    $safe_cid = str_replace(array('%3A', '%2F'), array('@', '='), urlencode($cid));
    if (strlen($safe_cid) > FILECACHE_CID_FILENAME_MAX) {
      $safe_cid =
        substr($safe_cid, 0, FILECACHE_CID_FILENAME_POS_BEFORE_MD5) .
        ',' .
        md5(substr($safe_cid, FILECACHE_CID_FILENAME_POS_BEFORE_MD5));
    }

    return $safe_cid;
  }

  /**
   * Return data from the persistent cache. Data may be stored as either plain
   * text or as serialized data. cache_get will automatically return
   * unserialized objects and arrays.
   *
   * @param $cid
   *   The cache ID of the data to retrieve.
   * @return
   *   The cache or FALSE on failure.
   */
  function get($cid) {
    if (!$this->ok || !is_string($cid)) {
      return FALSE;
    }

    $filename = $this->directory . '/' . $this->encode_cid($cid);

    // XXX should be in getMultiple() and get() to call getMultiple()
    $this->delete_flushed();

    // Use @ because cache entry may not exist
    $content = @file_get_contents($filename);
    if ($content === FALSE) {
      return FALSE;
    }
    $cache = @unserialize($content);
    if ($cache === FALSE) {
      // we are in the middle of cache_set
      $fh = fopen($filename, 'rb');
      if ($fh === FALSE) {
        return FALSE;
      }
      if (flock($fh, LOCK_SH) === FALSE) {
        fclose($fh);
        return FALSE;
      }
      $cache = @unserialize(@stream_get_contents($fh));
      if ($cache === FALSE ||
          flock($fh, LOCK_UN) === FALSE ||
          fclose($fh) === FALSE) {
        unlink($filename); // remove broken file
        flock($fh, LOCK_UN);
        fclose($fh);
        return FALSE;
      }
    }

    // XXX Should reproduce the cache_lifetime / cache_flush_$bin logic
    $cache_flush = variable_get('filecache_flush_' . $this->bin, 0);
    if ($cache->expire != CACHE_TEMPORARY && // XXX how to handle this?
        $cache->expire != CACHE_PERMANENT &&
        ($cache->expire < REQUEST_TIME ||
         ($cache_flush && $cache->created < $cache_flush))) {
      unlink($filename);
      return FALSE;
    }

    // Some systems don't update access time so we do it this way
    // XXX There's a chance that file no longer exists at this point
    // XXX but it's ok because we deal fine with broken cache entries
    // XXX should check only once in a page request if we have such
    // XXX filesystem and set $this->touch so that here we now what to do
    // XXX should be configurable
    // touch($filename);

    // XXX should assert($cache->cid == $cid)

    return $cache;
  }

  /**
   * Return data from the persistent cache when given an array of cache IDs.
   *
   * @param $cids
   *   An array of cache IDs for the data to retrieve. This is passed by
   *   reference, and will have the IDs successfully returned from cache
   *   removed.
   * @return
   *   An array of the items successfully returned from cache indexed by cid.
   */
  function getMultiple(&$cids) {
    $results = array();
    foreach ($cids as $cid) {
      $cache = $this->get($cid);
      if ($cache !== FALSE) {
        $results[$cid] = $cache;
      }
    }
    foreach (array_keys($results) as $cid) {
      if (($key = array_search($cid, $cids)) !== false) {
        unset($cids[$key]);
      }
    }
    return $results;
  }

  /**
   * Store data in the persistent cache.
   *
   * @param $cid
   *   The cache ID of the data to store.
   * @param $data
   *   The data to store in the cache. Complex data types will be automatically
   *   serialized before insertion.
   *   Strings will be stored as plain text and not serialized.
   * @param $expire
   *   One of the following values:
   *   - CACHE_PERMANENT: Indicates that the item should never be removed unless
   *     explicitly told to using cache_clear_all() with a cache ID.
   *   - CACHE_TEMPORARY: Indicates that the item should be removed at the next
   *     general cache wipe.
   *   - A Unix timestamp: Indicates that the item should be kept at least until
   *     the given time, after which it behaves like CACHE_TEMPORARY.
   */
  function set($cid, $data, $expire = CACHE_PERMANENT) {
    if (!is_string($cid)) {
      return;
    }

    $filename = $this->directory . '/' . $this->encode_cid($cid);

    if (!$this->ok || filecache_is_readdeleteonly()) {
      // Any cache set while the bin is not OK tries to invalidate the cache record.
      @unlink($filename);
      return;
    }

    // Open file for that entry, handling errors that may arise
    $fh = @fopen($filename, 'r+b');
    if ($fh === FALSE) {
      // If file doesn't exist, create it with a+w permissions
      $fh = fopen($filename, 'c+b');
      if ($fh !== FALSE) {
        if (!chmod($filename, FILECACHE_FILE_MODE)) {
          watchdog('filecache', 'Cannot chmod %filename', array('%filename' => $filename), WATCHDOG_CRITICAL);
          return;
        }
      }
      else {
        // most likely permission error - report it as critical error
        watchdog('filecache', 'Cannot open %filename', array('%filename' => $filename), WATCHDOG_CRITICAL);
        return;
      }
    }

    // Our safeguard for simultaneous writing in the same file
    if (flock($fh, LOCK_EX) === FALSE) {
      fclose($fh);
      return;
    }

    $cache = new StdClass; // XXX Should be custom class
    $cache->cid = $cid;
    $cache->created = REQUEST_TIME;
    $cache->expire = $expire;
    $cache->data = $data;

    if (ftruncate($fh, 0) === FALSE ||
        fwrite($fh, serialize($cache)) === FALSE ||
        flock($fh, LOCK_UN) === FALSE ||
        fclose($fh) === FALSE) {
      // XXX should not happen -> cleanup
      unlink($filename);
      flock($fh, LOCK_UN);
      fclose($fh);
      return;
    }
  }

  /**
   * Expire data from the cache. If called without arguments, expirable
   * entries will be cleared from the cache_page and cache_block bins.
   *
   * @param $cid
   *   If set, the cache ID to delete. Otherwise, all cache entries that can
   *   expire are deleted.
   * @param $wildcard
   *   If set to TRUE, the $cid is treated as a substring
   *   to match rather than a complete ID. The match is a right hand
   *   match. If '*' is given as $cid, the bin $bin will be emptied.
   */
  function clear($cid = NULL, $wildcard = FALSE) {
    global $user;

    if (!$this->ok) {
      return;
    }
    
    // parts are shamelessy copied from includes/cache.inc

    if (empty($cid)) {
      if (variable_get('cache_lifetime', 0)) {
        // We store the time in the current user's $user->cache variable which
        // will be saved into the sessions bin by _drupal_session_write(). We then
        // simulate that the cache was flushed for this user by not returning
        // cached data that was cached before the timestamp.
        $user->cache = REQUEST_TIME;

        $cache_flush = variable_get('cache_flush_' . $this->bin, 0);
        if ($cache_flush == 0) {
          // This is the first request to clear the cache, start a timer.
          variable_set('cache_flush_' . $this->bin, REQUEST_TIME);
        }
        elseif (REQUEST_TIME > ($cache_flush + variable_get('cache_lifetime', 0))) {
          // Clear the cache for everyone, cache_lifetime seconds have
          // passed since the first request to clear the cache.
          $this->delete_expired();
          variable_set('cache_flush_' . $this->bin, 0);
        }
      }
      else {
        // No minimum cache lifetime, flush all temporary cache entries now.
        $this->delete_expired();
      }
    }
    else {
      if ($wildcard) {
        if ($cid == '*') {
          $this->delete_wildcard('');
        }
        else {
          $this->delete_wildcard($cid);
        }
      }
      elseif (is_array($cid)) {
        foreach ($cid as $one_cid) {
          $this->delete_one($one_cid);
        }
      }
      else {
        $this->delete_one($cid);
      }
    }
  }

  /**
   * Delete a single cache object.
   *
   * @param $cid
   *   Cache ID.
   */
  protected function delete_one($cid) {
    $filename = $this->directory . '/' . $this->encode_cid($cid);
    @unlink($filename);
  }

  /**
   * List of all cache objects with specified prefix in their name.
   *
   * @param $cid_prefix
   *   Prefix for cache IDs to delete.
   */
  protected function all($cid_prefix = '') {
    $list = array();
    $filename_prefix = $this->encode_cid($cid_prefix);
    $filename_prefix_len = strlen($filename_prefix);
    if (is_dir($this->directory)) {
      $cwd = getcwd();
      chdir($this->directory);
      $dh = opendir('.');
      while (($filename = readdir($dh)) !== FALSE) {
        if (strncmp($filename, $filename_prefix, $filename_prefix_len) === 0) {
          $list[] = $filename;
        }
      }
      closedir($dh);
      chdir($cwd);
    }
    return $list;
  }

  /**
   * Delete all cache objects witch specified prefix in their name.
   *
   * @param $cid_prefix
   *   Prefix for cache IDs to delete.
   */
  protected function delete_wildcard($cid_prefix) {
    foreach ($this->all($cid_prefix) as $filename) {
      @unlink ($this->directory . '/' . $filename);
    }
  }

  /**
   * Delete expired cache entries.
   */
  function delete_expired($cache_flush = NULL) {
    if (!isset($cache_flush)) {
      $cache_flush = REQUEST_TIME;
    }

    $cache_size = 0;
    foreach ($this->all() as $filename) {
      $pathname = $this->directory . '/' . $filename;

      // gather statistics
      $stat = @stat($pathname);
      if ($stat === FALSE || is_dir($pathname)) {
        continue;
      }
      $file_size = $stat['blocks'] >= 0 ? $stat['blocks']*512 : $stat['size'];
      $cache_size += $file_size;

      $content = @file_get_contents($pathname);
      if ($content === FALSE) {
        continue;
      }
      $cache = @unserialize($content);
      if ($cache === FALSE) {
        continue;
      }
      if ($cache->expire == CACHE_PERMANENT) {
        continue;
      }
      $expiry_date = $cache->expire;
      if ($cache->expire == CACHE_TEMPORARY) {
        $expiry_date = $cache->created + variable_get('cache_lifetime', 0);
      }
      if ($expiry_date < $cache_flush) {
        @unlink($pathname);
        $cache_size -= $file_size;
      }
    } // foreach $filename

    return $cache_size;
}

  /**
   * Delete flushed cache entries.
   */
  protected function delete_flushed() {
    static $recursion = FALSE; // XXX how cache.inc survives this?
    if ($recursion) {
      return;
    }
    $recursion = TRUE;

    // Garbage collection necessary when enforcing a minimum cache lifetime.
    $cache_flush = variable_get('cache_flush_' . $this->bin, 0);
    if ($cache_flush && ($cache_flush + variable_get('cache_lifetime', 0) <= REQUEST_TIME)) {
      // Reset the variable immediately to prevent a meltdown in heavy load situations.
      variable_set('cache_flush_' . $this->bin, 0);
      // Time to flush old cache data
      $this->delete_expired($cache_flush);
    } // if $cache_flush

    $recursion = FALSE;
  }

  /**
   * Check if a cache bin is empty.
   *
   * A cache bin is considered empty if it does not contain any valid data for
   * any cache ID.
   *
   * @return
   *   TRUE if the cache bin specified is empty.
   */
  function isEmpty() {
    if (!$this->ok) {
      return FALSE;
    }
    return count($this->all()) === 0;
  }

}

