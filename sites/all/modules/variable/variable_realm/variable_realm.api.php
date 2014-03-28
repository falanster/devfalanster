<?php
/**
 * @file
 * Documents hooks provided by Variable Realm API.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Provides information about controller classes and weights for variable realms.
 *
 * This information is mainly used to build exportable realms as Features though
 * it may be used in the future to dinamically load realms upon request. For this
 * reason this may be defined in the main module and available at bootstrap time
 * when the realm is going to be used from some module hook_boot(). For this, the
 * module may need to implement any of the bootstrap hooks like hook_boot().
 *
 * @see i18n_variable_variable_realm_controller()
 *
 * @return array
 *   Associative array keyed by realm name. Each element is an array containing:
 *   - 'class', Class name implementing RealmControllerInterface.
 *   - 'weight', Default weight for this realm.
 */
function hook_variable_realm_controller() {
  $realm['language'] = array(
    'weight' => 100,
    'class' => 'VariableStoreRealmController',
  );
  return $realm;
}

/**
 * Provides human readable information about existing realms.
 *
 * This information is mainly used to build exportable realms as Features.
 *
 * @see i18n_variable_variable_realm_info()
 *
 * @return array
 *   Array keyed by realm name which contains the following elements:
 *   - 'title', Humam readable name for the realm.
 *   - 'keys', Associative array with human readable names for keys.
 */
function hook_variable_realm_info() {
  $realm['language'] = array(
    'title' => t('Language'),
    'keys' => locale_language_list('name', TRUE),
  );
  return $realm;
}

/**
 * @} End of "addtogroup hooks".
 */