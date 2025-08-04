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
// #include "debug.h"
// #include "action_layer.h"
// #include "version.h"

enum planka_layers {
  _QWERTY,
  _COLEMAK,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planka_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  VRSN
};

#define NUMPAD MO(_NUMPAD)
#define ALT_PSCR ALGR_T(KC_PSCR)
#define PLUS LSFT(KC_EQL)
#define UNDERS LSFT(KC_MINS)
#define MCR_C RALT(KC_C)
#define MCR_S RALT(KC_S)
#define MCR_Z RALT(KC_Z)
#define GRV_RSFT RSFT_T(KC_GRV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_planka68( /* Default QWERTY */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,    KC_HOME, ALT_PSCR, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,    KC_LBRC, KC_RBRC,  KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_RCTL, KC_A,   KC_S,    KC_D,    KC_F,  KC_G,    KC_MINS, KC_EQL,   KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, GRV_RSFT,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_QUOT, KC_DEL,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, NUMPAD, KC_LGUI, KC_LALT, LOWER,     KC_SPC,           KC_ENT,     RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_COLEMAK] = LAYOUT_planka68( /* Default Colemak */
        KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,    KC_HOME, ALT_PSCR, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,  KC_G,    KC_LBRC, KC_RBRC,  KC_J, KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_RCTL, KC_A,   KC_R,    KC_S,    KC_T,  KC_D,    KC_MINS, KC_EQL,   KC_H, KC_N,  KC_E,    KC_I,    KC_O,    GRV_RSFT,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,    KC_QUOT, KC_DEL,   KC_K, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, NUMPAD, KC_LGUI, KC_LALT, LOWER,      KC_SPC,           KC_ENT,    RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_NUMPAD] = LAYOUT_planka68( /* 2: Num pad layer */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH,    KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_NLCK,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS,    KC_TRNS,
        KC_TRNS, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_NO,  KC_KP_DOT,KC_KP_PLUS,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,         KC_TRNS,      KC_TRNS, KC_MPRV, KC_MPLY, KC_MSTP,        KC_MNXT
    ),
    [_LOWER] = LAYOUT_planka68( /* fn1 */
        KC_TRNS, KC_F1,   KC_F2,    KC_F3,   KC_F4,        KC_F5,   KC_F6,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS, 
        KC_TRNS, MCR_C,   MCR_S,    MCR_Z,   KC_TRNS,      KC_F7,   KC_F8,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_MINS, KC_EQL,   UNDERS,  PLUS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
        KC_TRNS, KC_UNDO, KC_AGAIN, KC_GRV,  LSFT(KC_GRV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,           KC_TRNS,         KC_TRNS,      KC_TRNS, KC_HOME, KC_PGDN,       KC_PGUP,       KC_END
    ),
    [_RAISE] = LAYOUT_planka68( /* fn2 */
        KC_F13,  KC_F14,  KC_F15,  KC_F16,        KC_F17,        KC_F18,  KC_NO, KC_TRNS, KC_F19,  KC_F20, KC_F21,       KC_F22,  KC_F23,        KC_F24,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,   KC_NO, KC_NO,   KC_F7,   KC_F8,  KC_F9,        KC_F10,  KC_F11,        KC_F12,
        KC_TRNS, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_GRV, LSFT(KC_GRV), KC_QUOT, LSFT(KC_QUOT), KC_TRNS,
        KC_TRNS, KC_DEL,  KC_CUT,  KC_COPY,       KC_PASTE,      KC_MENU, KC_NO, KC_TRNS, KC_CAPS, KC_INS, KC_PSCR,      KC_SLCK, KC_PAUS,       KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,          KC_TRNS,         KC_TRNS,      KC_TRNS,KC_MUTE,      KC_VOLD, KC_VOLU,       KC_MPLY
    ),
    [_ADJUST] = LAYOUT_planka68( /* fn1+fn2 */
        KC_ESC,  QWERTY,  COLEMAK, VRSN,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_NO,   KC_NO,   KC_LANG1,KC_LANG2,KC_LANG3,KC_LANG4,KC_LANG5,KC_NO,
        KC_INT7, KC_INT8, KC_INT9, KC_NO,   KC_UNDO, KC_NO,   KC_NO,   KC_NO,   KC_LANG6,KC_AGAIN,KC_LANG7,KC_LANG8,KC_LANG9,KC_NO,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WAKE,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,         KC_TRNS,      KC_TRNS, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT
    )
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);  // if raise and lower are active, switch to adjust layer
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    // case VRSN:
      // if (record->event.pressed) {
        // SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      // }
      // return false;
      // break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
