#include "cades.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

int lgui_cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 2) return DOUBLE_HOLD;
  return SINGLE_HOLD;
}

void on_lgui_finished (qk_tap_dance_state_t *state, void *user_data) {
  int dance_type = lgui_cur_dance(state);
  switch (dance_type) {
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_HOLD: register_code(KC_LGUI); break;
  }
}

void on_lgui_reset (qk_tap_dance_state_t *state, void *user_data) {
  int dance_type = lgui_cur_dance(state);
  switch (dance_type) {
    case SINGLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_HOLD: unregister_code(KC_LGUI);
  }
}

void on_left_bracket_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code(KC_RSFT);
    register_code(KC_9);
  } else {
    register_code(KC_LBRC);
  }
}

void on_left_bracket_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    unregister_code(KC_9);
    unregister_code(KC_RSFT);
  } else {
    unregister_code(KC_LBRC);
  }
}

void on_right_bracket_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    register_code(KC_RSFT);
    register_code(KC_0);
  } else {
    register_code(KC_RBRC);
  }
}

void on_right_bracket_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    unregister_code(KC_0);
    unregister_code(KC_RSFT);
  } else {
    unregister_code(KC_RBRC);
  }
}


qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LGUI]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,on_lgui_finished, on_lgui_reset),
  [TD_LBRC]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,on_left_bracket_finished, on_left_bracket_reset),
  [TD_RBRC]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,on_right_bracket_finished, on_right_bracket_reset),
  [TD_GRV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC) // Tap once for `, twice for Esc

};
