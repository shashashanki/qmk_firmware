/*
Copyright 2023 ma_po_daisuki

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

// #define COCOT_SCROLL_INV_DEFAULT 1
// #define COCOT_CPI_DEFAULT 4
// #define COCOT_SCROLL_DIV_DEFAULT 4
// #define COCOT_ROTATION_DEFAULT 5

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};

#define LW_SP LT(1,KC_SPACE)  // lower
#define LW_Y LT(1,KC_Y)  // lower
#define RS_SP LT(2,KC_SPACE)  // raise
#define RS_DEL LT(2,KC_DEL)  // raise
#define TR_EQ LT(3,KC_MINS)  // trackball
#define DEL_ALT KC_DEL//ALT_T(KC_DEL)
//#define SPC_SFT LSFT_T(KC_SPC)
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, MS_BTN3,               MS_BTN1,     LW_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_RBRC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, MS_BTN1,               MS_BTN2,     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_BSLS,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_INT1,
                        KC_LGUI, KC_LALT,   RS_SP,   LW_SP,                                 KC_ENTER, KC_BSPC,  RS_DEL,   TR_EQ
    ),
  [_LOWER] = LAYOUT(
       KC_TAB, S(KC_1), S(KC_2),   KC_UP, S(KC_4), S(KC_5), MS_BTN3,               MS_BTN1, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_MINS,
      KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, MS_BTN1,               MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,S(KC_SCLN), KC_QUOT,
      KC_LSFT, XXXXXXX, XXXXXXX, KC_HASH, XXXXXXX, XXXXXXX,                                 KC_LBRC,  KC_EQL, KC_INT3, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX,KC_SPACE,KC_SPACE,                                KC_ENTER, KC_BSPC, XXXXXXX, XXXXXXX
    ),
  [_RAISE] = LAYOUT(
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, MS_BTN3,               MS_BTN1,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_BSPC,
      KC_LCTL,   KC_F1, KC_LEFT, KC_DOWN, KC_RGHT,   KC_F5, MS_BTN1,               MS_BTN2,  KC_APP,   KC_UP,S(KC_RO), KC_UNDS, KC_DQUO, KC_COLN,
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                 KC_LEFT, KC_DOWN, KC_RGHT,  KC_DOT, KC_SLSH, KC_MINS,
                        XXXXXXX, XXXXXXX,KC_SPACE,KC_SPACE,                                KC_ENTER, KC_BSPC, XXXXXXX, XXXXXXX
    ),
  [_TRACKBALL] = LAYOUT(
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, XXXXXXX,            XXXXXXX, SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,            XXXXXXX, SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

/*
keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // First encoder
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}
*/


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        // rgblight_sethsv_range(HSV_BLUE, 0, 1);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        // rgblight_sethsv_range(HSV_RED, 0, 1);
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        // rgblight_sethsv_range(HSV_GREEN, 0, 1);
        cocot_set_scroll_mode(false);
        break;
    default:
        // rgblight_sethsv_range( 0, 0, 0, 0, 1);
        cocot_set_scroll_mode(false);
        break;
    }
    // rgblight_set_effect_range( 2, 10);
  return state;
};
