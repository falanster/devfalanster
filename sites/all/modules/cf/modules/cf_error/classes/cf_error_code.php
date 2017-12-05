<?php

/**
 * @file
 * Provides the derror exception class.
 */

/**
 * @addtogroup cf_error
 * @{
 */

class cf_error_code {
  private $type;
  private $backtrace;
  private $severity;


  /**
   * Class constructor.
   */
  public function __construct() {
    $this->type = 'bad variable';
    $this->backtrace = array();
    $this->severity = WATCHDOG_ERROR;
  }

  /**
   * Class destructor.
   */
  public function __destruct() {
    unset($type);
    unset($backtrace);
    unset($severity);
  }

  /**
   * Assigns a custom error type.
   *
   * @param string $type
   *   The category to which this message belongs. Can be any string, but the
   *   general practice is to use the name of the module calling watchdog().
   *
   * @see watchdog()
   */
  public function set_type($type) {
    $this->type = $type;
  }

  /**
   * Assign the backtrace.
   *
   * @param array $backtrace
   *   An array containing a backtrace log as returned by debug_backtrace().
   *
   * @see debug_backtrace()
   */
  public function set_backtrace(array $backtrace) {
    $this->backtrace = $backtrace;
  }

  /**
   * Assign the severity.
   *
   * @param string $severity
   *   The severity of the error.
   *   The possible numeric values are derived from watchdog_severity_levels().
   *
   * @see watchdog_severity_levels()
   */
  public function set_severity($severity) {
    $this->severity = $severity;
  }

  /**
   * Returns the error type.
   *
   * @return string
   *   The error type.
   */
  public function get_type() {
    return $this->type;
  }

  /**
   * Returns the error backtrace.
   *
   * @return array
   *   The error backtrace array.
   */
  public function get_backtrace() {
    return $this->backtrace;
  }

  /**
   * Returns the error severity.
   *
   * @return string
   *   Returns the type string.
   */
  public function get_severity() {
    return $this->severity;
  }

  /**
   * Get the file name for the error.
   *
   * @return string
   *   The file name containing the error in the last entry in the backtrace
   *   log.
   */
  public function get_error_file() {
    $error = $this->p_get_error();
    return $error['file'];
  }

  /**
   * Get the line number for the error.
   *
   * @return int
   *   The line number of the error in the last entry in the backtrace log.
   */
  public function get_error_line() {
    $error = $this->p_get_error();
    return $error['line'];
  }

  /**
   * Get the function name for the error.
   *
   * @return string
   *   The function name of the last entry in the backtrace log.
   */
  public function get_error_function() {
    $error = $this->p_get_error();
    return $error['function'];
  }

  /**
   * Get the arguments for the error.
   *
   * @return array
   *   An array of arguments passed to the last entry in the backtrace log.
   */
  public function get_error_arguments() {
    $error = $this->p_get_error();
    return $error['args'];
  }

  /**
   * Returns the last entry in the backtrace.
   *
   * The last entry in the backtrace does is referring to the last line
   * reported. The backtrace is a stack so the last reported entry turns out to
   * be the very first element in the array.
   *
   * @return array
   *   The last entry in the backtrace.
   */
  private function p_get_error() {
    $first = reset($backtrace);

    if ($first === FALSE) {
      return array('file' => '', 'line' => 0, 'function' => '', 'args' => array());
    }

    return $first;
  }
}

/**
 * @} End of '@addtogroup cf_error'.
 */
