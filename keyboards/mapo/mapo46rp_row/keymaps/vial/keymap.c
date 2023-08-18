// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "mapo46rp_row.h"

// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3
};

#define LW_SP LT(1,KC_SPACE)  // lower
#define LW_Y LT(1,KC_Y)  // lower
#define RS_SP LT(2,KC_INT5)  // raise
#define RS_DEL LT(2,KC_DEL)  // raise
#define TR_EQ LT(3,KC_MINS)  // trackball
#define DEL_ALT KC_DEL//ALT_T(KC_DEL)
#define GUI_TAB LGUI(KC_TAB)
//#define SPC_SFT LSFT_T(KC_SPC)
#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ A │ B │ C │ D │ E │ F │ G │ H │ I │ J │ K │ L │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
  [_BASE] = LAYOUT_ortho_4x12(
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_RBRC,
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_BSLS,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_INT1,
      KC_LGUI, KC_LALT,   RS_SP,   LW_SP, MS_BTN1, MS_BTN3,              MS_BTN2, MS_BTN2,KC_ENTER, KC_BSPC,  RS_DEL,   TR_EQ
    ),
  [_LOWER] = LAYOUT_ortho_4x12(
       KC_TAB, S(KC_1), S(KC_2),   KC_UP, S(KC_4), S(KC_5),              S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_MINS,
      KC_LCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,S(KC_SCLN), KC_QUOT,
      KC_LSFT, XXXXXXX, XXXXXXX, KC_HASH, XXXXXXX, XXXXXXX,              KC_LBRC,  KC_EQL, KC_INT3, XXXXXXX, XXXXXXX, XXXXXXX,
      GUI_TAB, XXXXXXX, KC_INT5,KC_SPACE, MS_BTN1, MS_BTN3,              MS_BTN2, MS_BTN2,KC_ENTER, KC_BSPC, XXXXXXX, XXXXXXX
    ),
  [_RAISE] = LAYOUT_ortho_4x12(
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,   KC_0,  KC_BSPC,
      KC_LCTL,   KC_F1, KC_LEFT, KC_DOWN, KC_RGHT,   KC_F5,               KC_APP,   KC_UP, XXXXXXX, KC_UNDS, KC_DQUO, KC_COLN,
      KC_LSFT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,              KC_LEFT, KC_DOWN, KC_RGHT,  KC_DOT, KC_SLSH, KC_MINS,
      XXXXXXX, XXXXXXX, XXXXXXX,KC_SPACE, MS_BTN1, MS_BTN3,              MS_BTN2, MS_BTN2,KC_ENTER, KC_BSPC, XXXXXXX, XXXXXXX
    ),
  [_TRACKBALL] = LAYOUT_ortho_4x12(
      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,              SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, XXXXXXX,
      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,              SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              SCRL_IN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [_RAISE] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [_TRACKBALL] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) }
};
#endif



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        cocot_set_scroll_mode(true);
        break;
    case _TRACKBALL:
        cocot_set_scroll_mode(false);
        break;
    default:
        cocot_set_scroll_mode(false);
        break;
    }
      return state;
};


// enum cocot_keycodes {
//     CPI_SW = USER00,
//     SCRL_SW,
//     ROT_R15,
//     ROT_L15,
//     SCRL_MO,
//     SCRL_TO,
//     SCRL_IN,
// };