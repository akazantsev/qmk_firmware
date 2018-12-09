/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _DV 0
#define _QW 1
#define _FN 2

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  LANG
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | 1      | 2      | 3      | 4      | 5      | -      | LANG   | =      | 6      | 7      | 8      | 9      | 0      | =      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    | '      | ,      | .      | P      | Y      | [      | \      | ]      | F      | G      | C      | R      | L      | /      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ESC    | A      | O      | E      | U      | I      | HOME   | DEL    | PG UP  | D      | H      | T      | N      | S      | -      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT | ;      | Q      | J      | K      | X      | DEL    | TG QW  | BACKSP | B      | M      | W      | V      | Z      | RSHIFT |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | LCTRL  | LGUI   | HOME   | END    | LALT   | FN     | SPACE  | LANG   | ENTER  | FN     | SPACE  | PG UP  | PG DN  | RGUI   | RCTRL  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_DV] = { /* Dvorak */
  { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, LANG,    KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL  },
  { KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_LBRC, KC_BSLS, KC_RBRC, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH  },
  { KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_DEL,  KC_PGUP, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS  },
  { KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_DEL,  TG(_QW), KC_BSPC, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT  },
  { KC_LCTL, KC_LGUI, KC_HOME, KC_END,  KC_LALT, MO(_FN), KC_SPC,  LANG,    KC_ENT,  MO(_FN), KC_RALT, KC_PGUP, KC_PGDN, KC_RGUI, KC_RCTL  },
 },

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | 1      | 2      | 3      | 4      | 5      | -      |        | =      | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | Z      | X      | C      | V      | B      |        | TG QW  |        | N      | M      | ,      | .      | /      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, _______, KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______  },
  { _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT  },
  { _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_DEL,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______  },
  { _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, TG(_QW), _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     | NUM LK | P/     | P*     | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB HD | RGB HI | P7     | P8     | P9     | -      | PR SCR | SCR LK | PAUSE  | VOL+   | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | RGB SD | RGB SI | P4     | P5     | P6     | LEFT   | UP     | DOWN   | RIGHT  | MUTE   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   |        | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        | VOL-   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   |        |        |        |        | RESET  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = { /* FUNCTION */
  { _______,   KC_F1,   KC_F2,   KC_F3, KC_F4,   KC_F5,   KC_NLCK, KC_SLSH, KC_ASTR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11   },
  { _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_TOG, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_PSCR, KC_SLCK, KC_PAUS, KC_VOLU, KC_F12   },
  { _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,_______, KC_P4,   KC_P5,   KC_P6,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_MUTE, _______  },
  { _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, _______, _______, KC_VOLD, _______  },
  { _______, _______, _______, _______, _______, MO(_FN), KC_P0,   _______, KC_PDOT, MO(_FN), _______, _______, _______, _______, RESET    },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
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
        layer_invert(_QW);
      }
      return false;
      break;
  }
  return true;
}
