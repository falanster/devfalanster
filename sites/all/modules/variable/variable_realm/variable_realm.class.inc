<?php
/**
 * @file
 * Variable realm controller
 */

/**
 * Realm Controller Interface.
 */
interface VariableRealmControllerInterface {
  /**
   * Class constructor.
   *
   * @param $realm
   *   Realm name.
   * @param $key
   *   Realm key.
   * @param $variables
   *   Optional array of variables to initialize the realm with.
   */
  public function __construct($realm, $key, $variables = NULL);
  /**
   * Initialize variables.
   */
  public function variable_init();
  /**
   * Get single variable.
   *
   * @param $name
   *   Variable name
   * @param $default
   *   Default value
   */
  public function variable_get($name, $default = NULL);
  /**
   * Set single variable.
   *
   * @param $name
   *   Variable name
   * @param $value
   *   Variable value
   */
  public function variable_set($name, $value);
  /**
   * Delete single variable.
   *
   * @param $name
   *   Variable name
   */
  public function variable_del($name);
  /**
   * List all current variable values.
   */
  public function variable_list();
}

/**
 * Base class, keeps static list of variables.
 */
class VariableRealmDefaultController implements VariableRealmControllerInterface {
  public $realm;
  public $key;
  protected $variables;
  /**
   * Class constructor.
   */
  public function __construct($realm, $key, $variables = NULL) {
    $this->realm = $realm;
    $this->key = $key;
    $this->variables = $variables;
  }

  /**
   * Initialize variables.
   */
  public function variable_init() {
    if (!isset($this->variables)) {
      $this->variables = array();
    }
  }
  /**
   * Get single variable.
   *
   * @param $name
   *   Variable name
   * @param $default
   *   Default value
   */
  public function variable_get($name, $default = NULL) {
    $this->variable_init();
    return isset($this->variables[$name]) ? $this->variables[$name] : $default;
  }
  /**
   * Set single variable.
   *
   * @param $name
   *   Variable name
   * @param $value
   *   Variable value
   */
  public function variable_set($name, $value) {
    $this->variable_init();
    $this->variables[$name] = $value;
  }
  /**
   * Delete single variable.
   *
   * @param $name
   *   Variable name
   */
  public function variable_del($name) {
    $this->variable_init();
    unset($this->variables[$name]);
  }
  /**
   * List all current variable values.
   */
  public function variable_list() {
    $this->variable_init();
    return $this->variables;
  }

}

/**
 * Controller for default system variables.
 */
class VariableRealmGlobal extends VariableRealmDefaultController {
  /**
   * Initialize variables.
   */
  public function variable_init() {
    if (!isset($this->variables)) {
      $this->variables = $GLOBALS['conf'];
    }
  }
  /**
   * Set single variable.
   *
   * @param $name
   *   Variable name
   * @param $value
   *   Variable value
   */
  public function variable_set($name, $value) {
    parent::variable_set($name, $value);
    variable_set($name, $value);
  }
  /**
   * Delete single variable.
   *
   * @param $name
   *   Variable name
   */
  public function variable_del($name) {
    parent::variable_del($name);
    variable_del($name);
  }
}