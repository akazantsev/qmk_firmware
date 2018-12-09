#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define DVRK 0 // default layer
#define QWRT 1 // QWERTY
#define SYMB 2 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  LANG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Dvorak layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |   \  |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   '  |   ,  |   .  |   P  |   Y  |  [   |           |   ]  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Esc   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------| Del  |           | BkSpc|------+------+------+------+------+--------|
 * |  LShift|   ;  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |      |      |  Alt |  Alt |                                       |  Alt |  Alt |      |      | RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | QWRT | LANG |       | PSCR | Ins  |
 *                                 ,------|------|------|       |------+------|------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 |Space |  L2  |------|       |------|  L2  | Enter|
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */

[DVRK] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_RPRN,
        KC_TAB,      KC_QUOT,      KC_COMM,   KC_DOT, KC_P,   KC_Y,   KC_LBRC,
        KC_ESC,         KC_A,         KC_O,   KC_E,   KC_U,   KC_I,
        KC_LSFT,     KC_SCLN,         KC_Q,   KC_J,   KC_K,   KC_X,   KC_DEL,
        KC_LCTRL,    KC_BSLS,      KC_PGDN,   KC_LALT,KC_LALT,
                                                      TG(QWRT),LANG,
                                                               KC_HOME,
                                                KC_SPC,MO(SYMB),KC_END,
        // right hand
             KC_BSLS,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        KC_EQL,
             KC_RBRC,     KC_F,   KC_G,  KC_C,   KC_R,   KC_L,        KC_SLSH,
                          KC_D,   KC_H,  KC_T,   KC_N,   KC_S,        KC_MINS,
             KC_BSPC,     KC_B,   KC_M,  KC_W,   KC_V,   KC_Z,        KC_RSFT,
                               KC_RALT,  KC_RALT,KC_DOWN,KC_RGHT,     KC_RCTRL,
             KC_PSCR, KC_INS,
             KC_PGUP,
             KC_PGDN, MO(SYMB),KC_ENT
    ),

/* Keymap 1: Qwerty layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |  =   |           |  ]   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |  \   |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | DVRK |      |       |      |      |
 *                                 ,------|------|------|       |------+------|------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[QWRT] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_EQL,
        KC_TRNS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_TRNS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_TRNS,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS,
                                                      KC_TRNS,KC_TRNS,
                                                              KC_TRNS,
                                              KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
             KC_RBRC,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,        KC_MINS,
             KC_BSLS,     KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,        KC_LBRC,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,     KC_QUOT,
             KC_TRNS,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,     KC_TRNS,
                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,
             KC_TRNS, KC_TRNS,
             KC_TRNS,
             KC_TRNS,KC_TRNS,KC_TRNS
    ),
/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Home | PgDn | PgUp | End  |------|           |------| Left |  Up  | Down | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | Mute |       | Play |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |VolUp |       | Next |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |VolDn |       | Prev |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,_______,_______,_______,_______,_______,_______,
       KC_TRNS,KC_TRNS,KC_HOME,KC_PGDN,KC_PGUP,KC_END,
       KC_TRNS,_______,_______,_______,_______,_______,_______,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_MUTE,
                                               KC_VOLU,
                               KC_TRNS,KC_TRNS,KC_VOLD,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, _______, _______,_______, _______, _______, KC_F12,
                KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, _______, _______,_______, _______, _______, _______,
                         _______,_______, _______, _______, _______,
       KC_MPLY, KC_TRNS,
       KC_MNXT,
       KC_MPRV, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case LANG:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LALT));
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_UP(X_LALT));
        SEND_STRING(SS_UP(X_LSHIFT));
        layer_invert(QWRT);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
