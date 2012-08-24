<?php
/**
 * @file vc_infusion.admin.inc
 */

/**
 * InfusionSoft settings form.
 */
function vc_infusion_settings_form($form, $form_state) {
  $form['appkey'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Your Infusionsoft application key'),
    '#default_value' => variable_get('vc_infusion_appkey', ''),
    '#description' => t('You can get application key !link', array('!link' => l(t('here'), 'http://help.infusionsoft.com/developers/vendorkey'))),
  );

  $form['appname'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#field_prefix' => 'https://',
    '#field_suffix' => '.infusionsoft.com/',
    '#title' => t('Your Infusionsoft application name'),
    '#default_value' => variable_get('vc_infusion_appname', ''),
  );

  $form['template'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact Template'),
    '#collapsible' => TRUE,
  );

  $form['template']['firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#default_value' => variable_get('vc_infusion_template_firstname', ''),
  );

  $form['template']['lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#default_value' => variable_get('vc_infusion_template_lastname', ''),
  );

  $form['template']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => variable_get('vc_infusion_template_email', '[user:mail]'),
  );

  $form['template']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('user'),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler for infusionsoft settings form.
 */
function vc_infusion_settings_form_submit($form, $form_state) {
  $v = &$form_state['values'];
  variable_set('vc_infusion_appkey', $v['appkey']);
  variable_set('vc_infusion_appname', $v['appname']);
  variable_set('vc_infusion_template_firstname', $v['firstname']);
  variable_set('vc_infusion_template_lastname', $v['lastname']);
  variable_set('vc_infusion_template_email', $v['email']);
}
