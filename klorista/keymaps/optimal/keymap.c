/*
    █         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
    █        █     █          ▄▀            ▀▄      █          █
    █       █      █        ▄▀                ▀▄    █          █
    █      █       █        █                  █    █          █
    █     █        █       █                    █   █          █
    █    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
    █   █ █        █       █                    █   █      █
    █  █   █       █        █                  █    █       █
    █ █     █      █        ▀▄                ▄▀    █        █
    ██       █     █          ▀▄            ▄▀      █         █
    █         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █

    ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
    D E F A U L T
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#ifdef HAPTIC_ENABLE
#include "drivers/haptic/drv2605l.h"
#endif //HAPTIC ENABLE


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘
enum klor_layers {
    _BASE,  // WIN
    _BASE2, // MAC
    _SYM, // symbols
    _OFFH,  // navigation
    _NAV,
    _NUM,   // numbers
    _LOL1,
    _LOL2
};
// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘
enum custom_keycodes {
    NAVL = SAFE_RANGE,
    NAVR,
    OS_SWAP,
    MAKE_H,
    // Encoder Maros
    SCRL_UP,
    SCRL_DN,
    REDO,
    UNDO,
    NEXT,
    PREV
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HOME ROW MODS ├────────────────────────────────┐
#define SHT_D MT(MOD_LSFT, KC_D)
#define CTL_F MT(MOD_LCTL, KC_F)

// RIGHT HOME ROW MODS ├───────────────────────────────┐
#define CTL_J MT(MOD_LCTL, KC_J)
#define SHT_K MT(MOD_RSFT, KC_K)

// LEFT THUMB MODS ├───────────────────────────────────┐
#define OFF_SPC LT(_OFFH, KC_SPC)
#define NUM_TAB LT(_NUM, KC_TAB)
#define ESC_GUI MT(MOD_LGUI, KC_ESC)

// RIGHT THUMB MODS ├──────────────────────────────────┐
#define NAVR_SPC LT(_NAV, KC_SPC)
#define SYM_ENT LT(_SYM, KC_ENT)
#define BSPC_ALT MT(MOD_LALT, KC_BSPC)


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ W I N D O W S                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │    Q    │    W    │    E    │    R    │    T    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    Y    │    U    │    I    │    O    │    P    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    `    │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    ;    │    "    │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │    Z    │    X    │    C    │    V    │    B    ││  MUTE  ││ SLEEP  ││    N    │    M    │    ,    │    .    │    /    │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │ ESC/GUI │  L-SPC  │  L-TAB  │                    │  L/ENTR │  L/SPC  │ BSP/ALT │
                                 └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */
   [_BASE] = LAYOUT_konrad(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_GRV,   KC_A,     KC_S,     SHT_D,    CTL_F,    KC_G,                          KC_H,     CTL_J,    SHT_K,    KC_L,     KC_SCLN,  KC_QUOT,
    XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   KC_MUTE, LGUI(KC_ESC), KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
                                  ESC_GUI,  OFF_SPC,  NUM_TAB,                       SYM_ENT,  NAVR_SPC, BSPC_ALT
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ A P P L E                                                 │
   └───────────────────────────────────────────────────────────┘
   */
   [_BASE2] = LAYOUT_konrad(
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_GRV,   KC_A,     KC_S,     SHT_D,    CTL_F,    KC_G,                          KC_H,     CTL_J,    SHT_K,    KC_L,     KC_SCLN,  KC_QUOT,
    XXXXXXX,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,   KC_MUTE, LGUI(KC_ESC), KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
                                  ESC_GUI,  OFF_SPC, NUM_TAB,                        SYM_ENT,  NAVR_SPC, BSPC_ALT
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ C O M B O S                                               │
   └───────────────────────────────────────────────────────────┘
   */
  // TODO:
  // - consider SH_TOGG for bot left key
  // - setup lock shortcut on mac (eg GUI+l on linux)
  [_OFFH] = LAYOUT_konrad(
               _______, _______,  _______,  C(KC_R),  C(KC_T),                       _______,  _______,  _______,  _______,  _______,
    TG(_LOL1), _______, _______,  KC_CAPS,  C(KC_F),  C(KC_G),                       _______,  _______,  _______,  _______,  _______,  _______,
    _______,   _______, _______,  _______,  C(KC_V),  C(KC_B),  OS_SWAP,    HF_TOGG, _______,  _______,  _______,  _______,  _______,  _______,
                                  KC_DEL,   _______,  KC_ENT,                        _______, S(KC_MINS),KC_DEL
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

   ┌───────────────────────────────────────────────────────────┐
   │ NAV                                                       │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │         │         │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │         │   <<    │    ||   │   >>    │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ├─╯                ╰─┤    ←    │    ↓    │    ↑    │    →    │    ▀    │  _LOL   │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │         │         │         ││        ││        ││   HOME  │   PG↓   │   PG↑   │   END   │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┼╰────────╯╰────────╯┼─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         │                    │         │         │         │
                                 └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘ */
   [_NAV] = LAYOUT_konrad(
              _______,  _______,  _______,  _______,  _______,                       _______,  KC_MPRV,  KC_MPLY, KC_MNXT , _______,
    _______,  _______,  _______,  _______,  _______,  _______,                       KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_MSTP,  TG(_LOL1),
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,   _______,  _______,
                                  _______,  _______,  _______,                       _______,  _______,  _______
 ),
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ $ y m b o l s                                             │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │         │         │    =    │    +    │         │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │    \    │    [    │    ]    │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    !    │    @    │    #    │    $    │    %    ├─╯                ╰─┤    ^    │    &    │    *    │    (    │    )    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │         │         │    |    │    -    │         ││        ││  BOOT  ││   PRNT  │    {    │    }    │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯╰────────╯├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   GUI   │         │         │                    │  ^^^^^  │         │         │
                                 └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘*/
   // rename to symbols
   [_SYM] = LAYOUT_konrad(
              _______,  _______,  KC_EQL,  S(KC_EQL), _______,                       KC_BSLS,  KC_LBRC,  KC_RBRC,  _______,  _______,
    _______,  S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),                       S(KC_6),  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),  _______,
    XXXXXXX,  _______,  _______, S(KC_BSLS), KC_MINS, _______,  _______,   QK_BOOT,  KC_PSCR,S(KC_LBRC),S(KC_RBRC),_______,  _______,  XXXXXXX,
                                  KC_LGUI,   _______, _______,                       _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌───────────────────────────────────────────────────────────┐
   │ N u m b e r s + FN                                        │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
             │   F1    │   F2    │   F3    │   F4    │   F5    │ ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮ │   F6    │   F7    │   F8    │   F9    │   F10   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    1    │    2    │    3    │    4    │    5    ├─╯                ╰─┤    6    │    7    │    8    │    9    │    0    │         │
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮╭────────╮├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   │         │   F11   │   F12   │  ^cpy   │  ^pste  │         ││  BOOT  ││        ││         │         │    ,    │    .    │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯╰────────╯├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │   ^^^   │                    │         │         │         │
                                 └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘
*/
   [_NUM] = LAYOUT_konrad(
             KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,                         KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    _______, KC_1,      KC_2,     KC_3,     KC_4,     KC_5,                          KC_6   ,  KC_7   ,  KC_8   ,  KC_9   ,  KC_0  ,  _______,
    XXXXXXX, KC_F11,    KC_F12, S(C(KC_C)),S(C(KC_V)),_______,  QK_BOOT,   _______,  _______,  _______,  _______,  _______,  _______, _______,
                                  _______,  _______,  _______,                       _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
    TODO: AUTO INVERT
   ┌───────────────────────────────────────────────────────────┐
   │ L O L 1 left-only                                         │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐          
             │    1    │    2    │    3    │    4    │    5    │ ╭╮╭╮╭╮╭X
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯
   │  SHFT   │    Q    │    W    │    E    │    R    │    T    ├─╯        
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮
   │         │    A    │    S    │    D    │    F    │    P    ││  QUIT  │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯
                                 │   ALT   │   SPC   │  L/CTRL │          
                                 └─────────┴─────────┴─────────┘          
*/
   [_LOL1] = LAYOUT_konrad(
              KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                          KC_5,     KC_4,     KC_3,     KC_2,     KC_1,
    KC_LSFT,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                          KC_T,     KC_R,     KC_E,     KC_W,     KC_Q,     KC_LSFT,
    XXXXXXX,  KC_A,     KC_S,     KC_D,     KC_F,     KC_P,     TO(_BASE),TO(_BASE), KC_P,     KC_F,     KC_D,     KC_S,     KC_A,     XXXXXXX,
                                  MOD_LALT, KC_SPC,   MO(_LOL2),                     MO(_LOL2),KC_SPC,   MOD_LALT
 ),
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸
   ┌───────────────────────────────────────────────────────────┐
   │ L O L 2 left-only                                         │
   └───────────────────────────────────────────────────────────┘
             ┌─────────┬─────────┬─────────┬─────────┬─────────┐          
             │   F1    │   F2    │   F3    │   F4    │   F5    │ ╭╮╭╮╭╮╭X
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯
   │   TAB   │  ctrl   │  ctrl   │  ctrl   │  ctrl   │    Y    ├─╯        
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤╭────────╮
   │         │         │         │    C    │   V     │    B    ││        │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤╰────────╯
                                 │         │         │         │          
                                 └─────────┴─────────┴─────────┘          
*/
   [_LOL2] = LAYOUT_konrad(
              KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                         KC_F5,    KC_F4,    KC_F3,    KC_F2,    KC_F1,
    KC_TAB,   C(KC_Q),  C(KC_W),  C(KC_E),  C(KC_R),  KC_Y,                          KC_Y,     C(KC_R),  C(KC_E),  C(KC_W),  C(KC_Q),  KC_TAB,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_C,     KC_V,     KC_B,     XXXXXXX,   XXXXXXX,  KC_B,     KC_V,     KC_C,     XXXXXXX,  XXXXXXX,  XXXXXXX,
                                  XXXXXXX,  XXXXXXX,  _______,                       _______,  XXXXXXX,  XXXXXXX
 )
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ H A P T I C   F E E D B A C K                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void keyboard_post_init_user(void) {
  // Call the post init code.
  #if HAPTIC_ENABLE
    // haptic_disable(); // disables per key haptic feedback by default
  #endif //HAPTIC ENABLE
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O L E D                                                                                                                                    │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

void matrix_scan_user(void) {
  // old dynamic macro function
}


// ┌───────────────────────────────────────────────────────────┐
// │ o l e d   g r a p h i c s                                 │
// └───────────────────────────────────────────────────────────┘

void render_os_lock_status(void) {
    static const char PROGMEM sep_v[] = {0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0};
    static const char PROGMEM sep_h1[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM sep_h2[] = {0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0xE1, 0};
    static const char PROGMEM face_1[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0xE1, 0};
    static const char PROGMEM face_2[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xE1, 0};
    static const char PROGMEM os_m_1[] = {0x95, 0x96, 0};
    static const char PROGMEM os_m_2[] = {0xB5, 0xB6, 0};
    static const char PROGMEM os_w_1[] = {0x97, 0x98, 0};
    static const char PROGMEM os_w_2[] = {0xB7, 0xB8, 0};
    static const char PROGMEM b_lock[] = {0xE1, 0xE1, 0};
    #ifdef HAPTIC_ENABLE
      static const char PROGMEM hap_en[] = {0xB1, 0xB2, 0};
    #endif

// os mode status ────────────────────────────────────────┐

    oled_write_ln_P(sep_v, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_1, false); // ──── MAC
    } else {
        oled_write_P(os_w_1, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_1, false);

    if (keymap_config.swap_lctl_lgui) {
        oled_write_P(os_m_2, false); // ──── MAC
    } else {
        oled_write_P(os_w_2, false); // ──── WIN
    }

    oled_write_P(sep_h1, false);
    oled_write_P(face_2, false);
    oled_write_ln_P(sep_v, false);

// hardware feature status ──────────────────────────────┐

    oled_write_P(sep_h2, false);

    #ifndef AUDIO_ENABLE
        oled_write_P(b_lock, false);
    #endif
    #ifndef HAPTIC_ENABLE
        oled_write_P(b_lock, false);
    #endif

    #ifdef AUDIO_ENABLE // ────────────────── AUDIO
        if (is_audio_on()) {
          oled_write_P(aud_en, false);
        } else {
          oled_write_P(aud_di, false);
        }
    #endif // AUDIO ENABLE

     #ifdef HAPTIC_ENABLE // ─────────────── HAPTIC
        oled_write_P(hap_en, false);
     #endif // HAPTIC ENABLE
}

int layerstate = 0;
char layer_state_str[24];

layer_state_t layer_state_set_kb(layer_state_t state) {
  // switch (get_highest_layer(layer_state | default_layer_state)) {
  switch (get_highest_layer(state)) {
  case _SYM:
      strcpy ( layer_state_str, "$ymbols          $:");
      break;
  case _OFFH:
      // update_tri_layer(_OFFH, _NAV, _SYM);
      strcpy ( layer_state_str, "Off Hand         :P");
      break;
  case _NAV:
      // update_tri_layer(_OFFH, _NAV, _SYM);
      strcpy ( layer_state_str, "Navigation       P:");
      break;
  case _NUM:
      strcpy ( layer_state_str, "Numbers          ;)");
      break;
  case _LOL1:
      strcpy ( layer_state_str, "LoL1");
      break;
  case _LOL2:
      strcpy ( layer_state_str, "LoL2");
      break;
  default:
      strcpy ( layer_state_str, "Qwerty           :D");
  }
  return state;
}


// ┌───────────────────────────────────────────────────────────┐
// │ w r i t e   t o   o l e d                                 │
// └───────────────────────────────────────────────────────────┘


bool oled_task_kb(void) {
    oled_invert(false);
    if (!oled_task_user()) {
        return false;
    }
    if(IS_LAYER_ON(_LOL1) || IS_LAYER_ON(_LOL2)){
        oled_clear();
        oled_invert(true);
        oled_set_cursor(0, 1);
        oled_write(" welcome", false);
        oled_set_cursor(0, 3);
        oled_write(" A atrox", false);

    } else{
    if (is_keyboard_master()) {  // ────────────────────────── Master

        oled_write_ln(layer_state_str, false);
        render_os_lock_status();

    } else {  // ─────────────────────────────────────────── Slave

        // BONGO no mo :'(
        // ─────────────────────────────────────────────────────┐
        oled_set_cursor(0, 0);
        oled_write("To-do :P", false);

        led_t led_state = host_keyboard_led_state();
        oled_set_cursor(0, 2);
        oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false);
        oled_set_cursor(0, 4);

      }
    }
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHT_K:
            return TAPPING_TERM - 150;
        case SHT_D:
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
// ┌───────────────────────────────────────────────────────────┐
// │ u t i l s                                                 │
// └───────────────────────────────────────────────────────────┘
    case OS_SWAP:
        if (record->event.pressed) {
          if (!keymap_config.swap_lctl_lgui) {
            keymap_config.swap_lctl_lgui = true;  // ─── MAC
            set_single_persistent_default_layer(_BASE2);
          }
          else {
            keymap_config.swap_lctl_lgui = false; // ─── WIN
            set_single_persistent_default_layer(_BASE);
          }
          #ifdef HAPTIC_ENABLE
            drv2605l_pulse(1);
          #endif // HAPTIC_ENABLE
        eeconfig_update_keymap(keymap_config.raw);
        clear_keyboard();  // ──── clear to prevent stuck keys
        return false;
      }
// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘
    case MAKE_H:
      if (record->event.pressed) {
        #ifdef KEYBOARD_klor_kb2040
          SEND_STRING ("qmk compile -kb klor/2040 -km optimal");
        #else
          SEND_STRING ("qmk compile -kb klor -km optimal");
        #endif
        tap_code(KC_ENTER);
      }
      break;
// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘
    case KC_MPLY:
      if (record->event.pressed) {
        #ifdef HAPTIC_ENABLE
              drv2605l_pulse(4);
        #endif // HAPTIC_ENABL
      }
      break;
    case SCRL_DN: // mac VSCode
      if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_PGDN);
        unregister_code(KC_LCTL);
      }
      break;
    case SCRL_UP: // mac VSCode
      if (record->event.pressed) {
        register_code(KC_LCTL);
        tap_code(KC_PGUP);
        unregister_code(KC_LCTL);
      }
      break;
  }
  return true;
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ E N C O D E R                                                                                                                              │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // Layer:                    Left encoder                                   Right encoder
    //                           down         up                                down          up
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD,     KC_VOLU),           ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_BASE2] =  { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(SCRL_DN,     SCRL_UP) },
    [_OFFH] =   { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(KC_U,        C(KC_R)) },
    [_NAV] =    { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(KC_U,        C(KC_R)) },
    [_SYM] =    { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(_______,     _______) },
    [_NUM] =    { ENCODER_CCW_CW(KC_BRID,     KC_BRIU),           ENCODER_CCW_CW(_______,     _______) },
    [_LOL1] =   { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(_______,     _______) },
    [_LOL2] =   { ENCODER_CCW_CW(_______,     _______),           ENCODER_CCW_CW(_______,     _______) },
};

/*
       ▄██████████████▄
       ████████████████
  ▄██████▀  ▀████▀  ▀██████▄
  ███████▄  ▄████▄  ▄███████
  ███████████▀▀▀▀███████████
  ▀█████████▀ ▄▄ ▀█████████▀
       ████▀ ▄██▄ ▀████
       ████▄▄████▄▄████
*/

