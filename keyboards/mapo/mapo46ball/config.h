// Copyright 2023 ma_po_daisuki (@ma_po_daisuki)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

/* Limit the maximum layer number to 8 */
#define LAYER_STATE_8BIT

/* Tapping */
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0


/* Trackball */
#ifdef POINTING_DEVICE_ENABLE
#    undef RP_SPI_USE_SPI0
#    define RP_SPI_USE_SPI0 TRUE
#    undef RP_SPI_USE_SPI1
#    define RP_SPI_USE_SPI1 FALSE
#    define SPI_DRIVER SPID0

#    define SPI_SCK_PIN GP2
#    define SPI_MISO_PIN GP4
#    define SPI_MOSI_PIN GP3
#endif

#ifndef PMW33XX_CS_PIN
#    define PMW33XX_CS_PIN GP1
#endif

// #define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y

//トラックボールのゆっくりな変位を検出するため
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

/* Encoder */
#define ENCODERS_PAD_A { GP28 }
#define ENCODERS_PAD_B { GP29 }
#define ENCODER_RESOLUTION 2
#define ENCODER_DIRECTION_FLIP