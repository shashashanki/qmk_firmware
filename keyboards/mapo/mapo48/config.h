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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x4D4D
#define PRODUCT_ID   0x0001
#define DEVICE_VER   0x0001
#define MANUFACTURER ma_po_daisuki
#define PRODUCT      mapo48

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

/* Limit the maximum layer number to 8 */
#define LAYER_STATE_8BIT

/* Rotary encoder */
/*
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 4
*/

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200


/* Trackball */
#ifdef POINTING_DEVICE_ENABLE
#    define SPI_SCK_PIN B1
#    define SPI_MISO_PIN B3
#    define SPI_MOSI_PIN B2

#endif

#ifndef PMW33XX_CS_PIN
#    define PMW33XX_CS_PIN B6
#endif

#define POINTING_DEVICE_INVERT_X

//#define POINTING_DEVICE_ROTATION_180