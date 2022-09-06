// ÖZKAN ÇELIK
// ozkancelik.com


#include QMK_KEYBOARD_H
#include "keymap_turkish_q.h"


enum cockpit_layer {
    _COLEMAK,
    _QWERTY,
    _LOWER,
    _RAISE,
    _FNL,
    _FNR,
    _ARROW,
    _ADJUST
};

enum cockpit_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY
};


#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define FNL    MO(_FNL)
#define FNR    MO(_FNR)
#define ARROW  MO(_ARROW)
#define ADJUST MO(_ADJUST)

#define LSFT_CAPS  LSFT_T(KC_CAPS)
#define RSFT_ENT   RSFT_T(KC_ENT)
#define RCTL_DQUO  RCTL_T(TR_DQUO)


#define FNR_SPC     LT(FNR, KC_SPC)
#define FNL_ENT     LT(FNL, KC_ENT)
#define ARROW_T LT(ARROW, KC_T)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// COLEMAK
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │  TAB │  Q   │  W   │  F   │  P   │  G   │                   │  J   │  L   │  U   │  Y   │   ;  │ BSPC │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │ CTRL │  A   │  R   │  S   │NAV T │  D   │                   │  H   │  N   │  E   │  I   │  O   │   "  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │SFT_CL│ALT Z │CTL X │SFT C │  V   │  B   │                   │  K   │  M   │SFT , │CTL . │ALT / │ ENT  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯

  [_COLEMAK] = LAYOUT_cockpit(
    KC_TAB,     TR_Q,          TR_W,          TR_F,          TR_P,     TR_G,             TR_J,  TR_L,  TR_U,             TR_Y,            TR_SCLN,   KC_BSPC,
    KC_LCTRL,   TR_A,          TR_R,          TR_S,          ARROW_T,  TR_D,             TR_H,  TR_N,  TR_E,             TR_IDOT,         TR_O,     RCTL_DQUO,
    LSFT_CAPS,  LALT_T(TR_Z),  LCTL_T(TR_X),  LSFT_T(TR_C),  TR_V,     TR_B,             TR_K,  TR_M,  RSFT_T(TR_COMM),  RCTL_T(TR_DOT),  TR_SLSH,  RSFT_ENT,
                                                                          KC_MPLY,   KC_MUTE,
                                         KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                                 KC_UP,
                                                                    KC_LEFT,    KC_DOWN,  KC_RGHT

  ),


  [_QWERTY] = LAYOUT_cockpit(
    KC_TAB,      TR_Q,  TR_W,  TR_E,  TR_R,  TR_T,                 TR_Y,  TR_U,  TR_IDOT,  TR_O,    TR_P,     KC_BSPC,
    KC_LCTRL,    TR_A,  TR_S,  TR_D,  TR_F,  TR_G,                 TR_H,  TR_J,  TR_K,     TR_L,    TR_SCLN,  RCTL_DQUO,
    LSFT_CAPS,   TR_Z,  TR_X,  TR_C,  TR_V,  TR_B,                 TR_N,  TR_M,  TR_COMM,  TR_DOT,  TR_SLSH,  RSFT_ENT,
                                                  KC_MPLY,   KC_MUTE,
                 KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                         KC_UP,
                                            KC_LEFT,    KC_DOWN,  KC_RGHT

  ),
  
// LOWER
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │      │      │      │                   │  (   │  )   │  =   │  &   │  |   │ DEL  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │  {   │  }   │  _   │  $   │  #   │   '  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │  [   │  ]   │  <   │  >   │  \   │ ENT  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_LOWER] = LAYOUT_cockpit(
    KC_ESC,   _______,  _______,   _______,  _______,   _______,               TR_LPRN,  TR_RPRN,   TR_EQL,   TR_AMPR,  TR_PIPE,  KC_DEL,
    _______,  _______,  _______,   _______,  _______,   _______,               TR_LCBR,  TR_RCBR,   TR_UNDS,  TR_DLR,   TR_HASH,  TR_QUOT,
    _______,  _______,  _______,   _______,  _______,   _______,               TR_LBRC,  TR_RBRC,   TR_LABK,  TR_RABK,  TR_BSLS,  KC_END,
                                                               KC_MPLY,   KC_MUTE,
                              KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                      KC_UP,
                                                         KC_LEFT,    KC_DOWN,  KC_RGHT

  ),

 
// RAISE
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │  /   │  1   │  2   │  3   │  -   │                   │  F1  │  F2  │  F3  │  F4  │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  *   │  4   │  5   │  6   │  +   │                   │  F5  │  F6  │  F7  │  F8  │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  %   │  7   │  8   │  9   │  0   │                   │  F9  │  F10 │ F11  │  F1  │      │      │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯
                  
   

  [_RAISE] = LAYOUT_cockpit(
    KC_ESC,   TR_SLSH,  TR_1,  TR_2,  TR_3,  TR_MINS,          KC_F1,  KC_F2,   KC_F3,   KC_F4,   _______,  _______,
    _______,  TR_ASTR,  TR_4,  TR_5,  TR_6,  TR_PLUS,          KC_F5,  KC_F6,   KC_F7,   KC_F8,   _______,  _______,
    _______,  TR_PERC,  TR_7,  TR_8,  TR_9,  TR_0,             KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,  _______,
                                                KC_MPLY,   KC_MUTE,
               KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                       KC_UP,
                                          KC_LEFT,    KC_DOWN,  KC_RGHT

  ),

 
// FNR 
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │  €   │  £   │  Ğ   │                   │      │      │      │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │  !   │  @   │  Ş   │  ₺   │      │                   │      │      │      │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │  Ç   │      │      │                   │      │      │      │      │      │      │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_FNR] = LAYOUT_cockpit(
    KC_ESC,   _______,  _______,  TR_LIRA,  TR_EURO,  TR_GBRV,               _______,  _______,  _______,  _______,  _______,  _______,
    _______,  TR_EXLM,  TR_AT,    TR_SCED,  _______,  TR_PND,                _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  TR_CCED,  _______,  _______,               _______,  _______,  _______,  _______,  _______,  _______,
                                                          KC_MPLY,   KC_MUTE,
                         KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                 KC_UP,
                                                    KC_LEFT,    KC_DOWN,  KC_RGHT

  ),

// FNL
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │      │      │      │                   │      │      │  Ü   │      │  :   │ DEL  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │      │      │  I   │  I   │  Ö   │   '  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │      │      │  ^   │  ~   │  ?   │ ENT  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_FNL] = LAYOUT_cockpit(
    KC_ESC,   _______,  _______,  _______,  _______,  _______,               _______,  _______,  TR_UDIA,   _______,  TR_COLN,  KC_DEL,
    _______,  _______,  _______,  _______,  _______,  _______,               _______,  _______,  S(TR_I),  TR_I,      TR_ODIA,  TR_GRV,
    _______,  _______,  _______,  _______,  _______,  _______,               _______,  _______,  TR_CIRC,  TR_TILD,   TR_QUES,  KC_RGHT,
                                                          KC_MPLY,   KC_MUTE,
                         KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                 KC_UP,
                                                    KC_LEFT,    KC_DOWN,  KC_RGHT

  ),
  

// ARROW
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │ ESC  │      │      │      │      │      │                   │C_PREV│ PGUP │  UP  │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │NAV T │      │                   │ HOME │ LEFT │ DOWN │ RGHT │ END  │MPLY  │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │C_NEXT│PGDOWN│      │VLDOWN│ VLUP │MUTE  │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_ARROW] = LAYOUT_cockpit(
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MPRV,   KC_PGUP,    KC_UP,      _______,     _______,    _______, 
    _______,  _______,  _______,   _______,  _______,   _______,               KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RGHT,     KC_END,     KC_MPLY, 
    _______,  _______,  _______,   _______,  _______,   _______,               KC_MNXT,   KC_PGDOWN,  _______,    KC_VOLD,     KC_VOLU,    KC_MUTE, 
                                                              KC_MPLY,   KC_MUTE,
                             KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                     KC_UP,
                                                        KC_LEFT,    KC_DOWN,  KC_RGHT

  ),




// ADJUST
// ╭──────┬──────┬──────┬──────┬──────┬──────╮                   ╭──────┬──────┬──────┬──────┬──────┬──────╮
// │      │      │      │      │      │      │                   │      │      │      │      │ QWERY│COLEMK│
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │      │      │      │      │      │      │
// ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
// │      │      │      │      │      │      │                   │ RESET│      │      │      │      │      │
// ╰──────┴──────┴──────┴──────┴──────┴──────┼─────────┬─────────┼──────┴──────┴──────┴──────┴──────┴──────╯
//                                           │  MPLY   │  MUTE   │
//                     ╭──────┬──────┬───────┼─────────┴─────────┼──────┬──────┬──────╮
//                     │  ALT │LOWER │  FNL  │                   │ FNR  │RAISE │  WIN │
//                     ╰──────┴──────┴───────┴─────┬──────┬──────┴──────┴──────┴──────╯
//                                                 │  UP  │
//                                          ╭──────┼──────┼──────╮
//                                          │ LEFT │ DOWN │ RIGHT│
//                                          ╰──────┴──────┴──────╯


  [_ADJUST] = LAYOUT_cockpit(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,                   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QWERTY,   COLEMAK,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,                   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,                   RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                               KC_MPLY,   KC_MUTE,
                              KC_LALT,   LOWER,    FNL_ENT,                           FNR_SPC,   RAISE,   KC_RGUI,    
                                                                      KC_UP,
                                                         KC_LEFT,    KC_DOWN,  KC_RGHT

  ),
};



layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
}