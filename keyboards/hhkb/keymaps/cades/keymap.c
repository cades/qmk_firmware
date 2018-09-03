/*  -*-  eval: (turn-on-orgtbl); -*-
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H
#include "cades.h"

#define LEADER_TIMEOUT 300

#define BASE 0
#define HHKB 1
#define MEDIA 2
#define ESC 3
#define ARROW 4
#define EMACS_CTL 5
#define EMACS_OPT 6

// macro config
// https://docs.qmk.fm/#/feature_macros
enum custom_keycodes {
  MY_DEL = SAFE_RANGE,
  MY_PGUP,
  MY_PGDN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case MY_DEL:
    if (record->event.pressed) {
      unregister_code(KC_LCTL);
      register_code(KC_DEL);
    } else {
      unregister_code(KC_DEL);
      register_code(KC_LCTL);
    }
    return false;
  case MY_PGUP:
    if (record->event.pressed) {
      unregister_code(KC_LCTL);
      register_code(KC_PGUP);
    } else {
      unregister_code(KC_PGUP);
      register_code(KC_LCTL);
    }
    return false;
  case MY_PGDN:
    if (record->event.pressed) {
      unregister_code(KC_LCTL);
      register_code(KC_PGDN);
    } else {
      unregister_code(KC_PGDN);
      register_code(KC_LCTL);
    }
    return false;
  }
  return true;
};

// leader key config
// https://docs.qmk.fm/#/feature_leader_key
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_E) {
      SEND_STRING("cadeskao@gmail.com");
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("yarn run start\n");
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING("yarn run test\n");
    }
    SEQ_ONE_KEY(KC_D) {
      SEND_STRING("yarn run dev\n");
    }
  }
}

// keymap config
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-------+-------+---|
     | ` or ESC  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =     | \     | \ |
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-------+-------+---|
     | LT(M,TAB) | Q | W | E | R | T | Y | U | I | O | P | [     | ]     | Backs |
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-------+-------+
     |LM(EC,Ctrl)| A | S | D | F | G | H | J | K | L | ; | '     | Ent   |
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-------+
     | Shift     | Z | X | C | V | B | N | M | , | . | / | Shift | Fn    |
     |-----------+---+---+---+---+---+---+---+---+---+---+-------+-------+

            |-------------+------+---------------+------+-----|
            | LM(EO,LAlt) | LGUI | LT(Arrow,SPC) | LEAD | ESC |
            |-------------+------+---------------+------+-----|
    */

    [BASE] = LAYOUT(
        TD(TD_GRV_ESC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_BSLS,
        LT(MEDIA, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_LBRC), TD(TD_RBRC), KC_BSPC,
        LM(EMACS_CTL, MOD_LCTL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(HHKB),
        LM(EMACS_OPT, MOD_LALT), KC_LGUI, /*        */ LT(ARROW, KC_SPC), KC_LEAD, KC_ESC),

    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    |     |     |     | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [HHKB] = LAYOUT(
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Media Layer: (Tab)
      |--------+-----+------+------+---+---+------+------+-------+-------+-------+-----+------+------+---|
      |        | Br- | Br+  |      |   |   |      |      | PvTrk | Pl/Ps | NxTrk | Mut | VolD | VolU |   |
      |--------+-----+------+------+---+---+------+------+-------+-------+-------+-----+------+------+---|
      | ****** |     | BTN2 | BTN1 |   |   |      |      | MS_U  |       |       |     |      |      |   |
      |--------+-----+------+------+---+---+------+------+-------+-------+-------+-----+------+------+---|
      |        |     |      |      |   |   | BTN1 | MS_L | MS_D  | MS_R  |       |     |      |      |   |
      |--------+-----+------+------+---+---+------+------+-------+-------+-------+-----+------+------+---|
      |        |     |      |      |   |   | BTN2 | ACL0 | ACL1  | ACL2  |       |     |      |      |   |
      |--------+-----+------+------+---+---+------+------+-------+-------+-------+-----+------+------+---|

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [MEDIA] = LAYOUT(
        KC_TRNS, KC_SLCK, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* ESC Layer: (ROpt)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | ESC  |     |     |     |     |    |    |    |    |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+
      |      |     |     |     |    |    |    |    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+
      |      |     |     |     |    |    |    |    |     |     |     |     |*******|
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [ESC] = LAYOUT(
        KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Arrow Layer: (Space)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |     |    |    |    |    |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |HOME|  UP | END |     |     |       |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+
      |      |     |     |     |    |    |PgUp|LEFT| DOWN| RGHT|     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+
      |      |     |     |     |    |    |PgDn|    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+

                 |------+------+----------------------+------+------+
                 |      |      |**********************|      |      |
                 |------+------+----------------------+------+------+

     */

    [ARROW] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Emacs Ctl Layer: (LCtrl)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |     |    |    |    |    |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+
      |******|     |     |Del  |    |    |    |    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+
      |      |     |     |     |PgDn|    |    |    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+

                 |------+------+----------------------+------+------+
                 |      |      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [EMACS_CTL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MY_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MY_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    /* Emacs Opt Layer: (LOpt)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |     |    |    |    |    |     |     |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    |    |    |     |     |     |     |       |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+
      |      |     |     |     |    |    |    |    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+
      |      |     |     |     |PgUp|    |    |    |     |     |     |     |       |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+

                 |------+------+----------------------+------+------+
                 |******|      |                      |      |      |
                 |------+------+----------------------+------+------+

     */

    [EMACS_OPT] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch (id)
    {
    case 0:
        if (record->event.pressed)
        {
            register_code(KC_RSFT);
        }
        else
        {
            unregister_code(KC_RSFT);
        }
        break;
    }
    return MACRO_NONE;
};
