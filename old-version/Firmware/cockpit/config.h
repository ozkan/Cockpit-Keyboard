#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x4648
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0001
#define MANUFACTURER ozkancelik
#define PRODUCT cockpit

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/*
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS \
    { F4, F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS \
    { D1, D0, D4, C6, D7, E6 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { B4, D2 }
#define ENCODERS_PAD_B { B5, D3 }

#define ENCODER_RESOLUTION 4 
// #define ENCODER_RESOLUTIONS { 4, 2 }


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
