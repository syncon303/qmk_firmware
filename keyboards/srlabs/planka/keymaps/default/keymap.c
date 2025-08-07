/* Copyright 2018 Bojan Burkeljc
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
#include QMK_KEYBOARD_H

enum planka_layers {
  _QWERTY,
  _COLEMAK,
  _GAMING,
  _NUMPAD,
  _LOWER=4,
  _RAISE,
  _ADJUST
};

enum planka_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  VRSN
};

// #define NUMPAD MO(_NUMPAD)
#define NUMPAD LT(_NUMPAD, KC_APP)

#define ALT_PSCR ALGR_T(KC_PSCR)
#define PLUS S(KC_EQL)
#define UNDERS S(KC_MINS)
#define MCR_C RALT(KC_C)
#define MCR_S RALT(KC_S)
#define MCR_Z RALT(KC_Z)
#define GRV_RSFT RSFT_T(KC_GRV)
#define QWERTY PDF(_QWERTY)
#define COLEMAK PDF(_COLEMAK)
#define GAMING PDF(_GAMING)
#define VD_LEFT C(G(KC_LEFT))
#define VD_RIGHT C(G(KC_RIGHT))

#define SFT_SPC LSFT_T(KC_SPC)
#define SFT_ENT RSFT_T(KC_ENT)

// home row modifier definitions
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)

// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( /* Default QWERTY */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,    KC_HOME, ALT_PSCR, KC_6, KC_7,  KC_8,    KC_9,    KC_0,     KC_BSPC,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,    KC_LBRC, KC_RBRC,  KC_Y, KC_U,  KC_I,    KC_O,    KC_P,     KC_BSLS,
        KC_RCTL, GUI_A,  ALT_S,   SFT_D,   CTL_F, KC_G,    KC_MINS, KC_EQL,   KC_H, CTL_J, SFT_K,   ALT_L,   GUI_SCLN, GRV_RSFT,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_QUOT, KC_DEL,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
        KC_LCTL, NUMPAD, KC_LGUI, KC_LALT, TL_LOWR,  SFT_SPC,          SFT_ENT,   TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
    ),
    [_COLEMAK] = LAYOUT( /* Default Colemak */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,    KC_HOME, ALT_PSCR, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,  KC_G,    KC_LBRC, KC_RBRC,  KC_J, KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_RCTL, GUI_A,  ALT_R,   SFT_S,   CTRL_T,KC_D,    KC_MINS, KC_EQL,   KC_H, CTL_N, SFT_E,   ALT_I,   GUI_O,   GRV_RSFT,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_QUOT, KC_DEL,   KC_K, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, NUMPAD, KC_LGUI, KC_LALT, TL_LOWR,   SFT_SPC,          SFT_ENT,  TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_GAMING] = LAYOUT( /* Default QWERTY */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,    KC_HOME, ALT_PSCR, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,    KC_LBRC, KC_RBRC,  KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_RCTL, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,    KC_MINS, KC_EQL,   KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, GRV_RSFT,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_QUOT, KC_DEL,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, NUMPAD, KC_LGUI, KC_LALT, TL_LOWR,   KC_SPC,           KC_ENT,   TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_NUMPAD] = LAYOUT( /* 2: Num pad layer */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH,    _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_NUM,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS,    _______,
        _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______, _______, _______, KC_KP_0, KC_NO,  KC_KP_DOT,KC_KP_PLUS,     _______,
        _______, _______, _______, _______, _______,      _______,         _______,      _______, KC_MPRV, KC_MPLY, KC_MSTP,        KC_MNXT
    ),
    [_LOWER] = LAYOUT( /* fn1 */
        _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,        KC_F5,   KC_F6,   _______, _______, _______, _______, _______,       _______,       _______,
        _______, MCR_C,   MCR_S,    MCR_Z,   _______,      KC_F7,   KC_F8,   _______, _______, _______, _______, _______,       _______,       _______,
        _______, KC_MINS, KC_EQL,   UNDERS,  PLUS,         _______, _______, _______, _______, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), _______,
        _______, KC_UNDO, KC_AGAIN, KC_GRV,  LSFT(KC_GRV), _______, _______, _______, _______, _______, _______, _______,       _______,       _______,
        _______, _______, _______,  _______, _______,           _______,         _______,      _______, KC_HOME, KC_PGDN,       KC_PGUP,       KC_END
    ),
    [_RAISE] = LAYOUT( /* fn2 */
        KC_F13,  KC_F14,  KC_F15,  KC_F16,        KC_F17,        KC_F18,  KC_NO, _______, KC_F19,  KC_F20, KC_F21,       KC_F22,  KC_F23,        KC_F24,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,   KC_NO, KC_NO,   KC_F7,   KC_F8,  KC_F9,        KC_F10,  KC_F11,        KC_F12,
        _______, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_GRV, LSFT(KC_GRV), KC_QUOT, LSFT(KC_QUOT), _______,
        _______, KC_DEL,  KC_CUT,  KC_COPY,       KC_PASTE,      KC_MENU, KC_NO, _______, KC_CAPS, KC_INS, KC_PSCR,      KC_SCRL, KC_PAUS,       _______,
        _______, _______, _______, _______,       _______,          _______,         _______,      _______,KC_MUTE,      KC_VOLD, KC_VOLU,       KC_MPLY
    ),
    [_ADJUST] = LAYOUT( /* fn1+fn2 */
        QK_GESC, QWERTY,  COLEMAK, GAMING,  VRSN,   KC_NO,   KC_NO,QK_BOOTLOADER,KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_NO,   KC_NO,   KC_LNG1, KC_LNG2, KC_LNG3, KC_LNG4, KC_LNG5, KC_NO,
        KC_INT7, KC_INT8, KC_INT9, KC_NO,   KC_UNDO, KC_NO,   KC_NO,   KC_NO,   KC_LNG6, KC_AGAIN,KC_LNG7, KC_LNG8, KC_LNG9, KC_NO,
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WAKE,
        _______, _______, _______, _______, _______,      _______,         _______,      _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT
    )
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);  // if raise and lower are active, switch to adjust layer
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;

    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;

    // case VRSN:
      // if (record->event.pressed) {
        // SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      // }
      // return false;
      // break;
  }
  return true;
}
