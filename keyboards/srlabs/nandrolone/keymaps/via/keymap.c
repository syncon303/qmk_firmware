// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* EEPROM data structure */
// typedef union {
//   uint32_t raw;
//   struct {
//     uint8_t      :1;
//   };
// } user_config_t;

// user_config_t user_config;

enum nandrolone_layers {
  _QWERTY,
  _COLEMAK,
  _GAMING,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planka_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  VRSN,
  UC_DEG,
  UC_EURO
};

#define NUMPAD MO(_NUMPAD)
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
    /* Qwerty default layer */
    [_QWERTY] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_RCTL, GUI_A,   ALT_S,   SFT_D,   CTL_F,   KC_G,    KC_MINS,        KC_EQL,  KC_H,    CTL_J,   SFT_K,   ALT_L,   GUI_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,        KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, NUMPAD,  KC_LGUI, /*scroll*/                 LOWER,          RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_DEL,  SFT_SPC, KC_LALT,        KC_RALT, SFT_ENT,
                                                     KC_SPC,  KC_LCTL,        KC_RCTL, KC_ENT,  KC_BSPC
    ),
    /* Colemak default layer */
    [_COLEMAK] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,        KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_RCTL, GUI_A,   ALT_R,   SFT_S,   CTRL_T,  KC_D,    KC_MINS,        KC_EQL,  KC_H,    CTL_N,   SFT_E,   ALT_I,   GUI_O,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,        KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, NUMPAD,  KC_LGUI, /*scroll*/                 LOWER,          RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_DEL,  SFT_SPC, KC_LALT,        KC_RALT, SFT_ENT,
                                                     KC_SPC,  KC_LCTL,        KC_RCTL, KC_ENT,  KC_BSPC
    ),
    [_GAMING] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,        KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,        KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_LCTL, NUMPAD,  KC_LGUI, /*scroll*/                 LOWER,          RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_DEL,  KC_LSFT, KC_LALT,        KC_RALT, SFT_ENT,
                                                     KC_SPC,  KC_LCTL,        KC_RCTL, KC_ENT,  KC_BSPC
    ),
    /* Numpad on right half */
    [_NUMPAD] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______,        KC_NUM,  _______, KC_KP_7, KC_KP_8, KC_KP_9,   KC_KP_SLASH,
        _______, _______, _______, _______, _______,  _______, _______,        _______, _______, KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_ASTERISK,
        _______, _______, _______, _______, _______,  _______, _______,        _______, _______, KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_MINUS,
        _______, _______, KC_CUT,  KC_COPY, KC_PASTE, KC_MENU, _______,        _______, _______, KC_KP_0, KC_NO,   KC_KP_DOT, KC_KP_PLUS,
        _______, _______, _______, /*scroll*/                  _______,        _______,          KC_MPRV, KC_MPLY, KC_MSTP,   KC_MNXT,
                                            KC_APP,   _______, _______,        _______, _______,
                                                      _______, _______,        _______, _______, _______
    ),

    [_LOWER] = LAYOUT(
        QK_GESC, KC_F1,   KC_F2,   KC_F3,      KC_F4,     KC_F5,   KC_F6,          KC_MUTE, _______, _______, _______, _______,    _______,
        _______, _______, _______, UC_EURO,    _______,   KC_F7,   KC_F8,          _______, _______, _______, _______, UC_DEG,     _______,
        _______, KC_MINS, KC_EQL,  S(KC_MINS), S(KC_EQL), _______, _______,        _______, _______, KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC),
        _______, KC_DEL,  KC_CUT,  KC_COPY,    KC_PASTE,  KC_MENU, _______,        _______, _______, _______, _______, _______,    _______,
        _______, _______, _______, /*scroll*/                      _______,        _______,          KC_HOME, KC_PGDN, KC_PGUP,    KC_END,
                                               _______,   _______, _______,        _______, _______,
                                                          _______, _______,        _______, _______, _______
    ),
    /* Raise layer features joystick as a mouse pointer */
    [_RAISE] = LAYOUT(
        KC_F13,  KC_F14,  KC_F15,  KC_F16,     KC_F17,     KC_F18,  _______,        KC_F19,  KC_F20,   KC_F21,  KC_F22,    KC_F23,  KC_F24,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,      KC_F5,      KC_F6,   _______,        KC_F7,   KC_F8,    KC_F9,   KC_F10,    KC_F11,  KC_F12,
        _______, KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC), KC_NO,   _______,        VD_LEFT, VD_RIGHT, KC_GRV,  S(KC_GRV), KC_QUOT, S(KC_QUOT),
        _______, KC_DEL,  KC_CUT,  KC_COPY,    KC_PASTE,   KC_MENU, _______,        _______, KC_CAPS,  KC_INS,  KC_PSCR,   KC_SCRL, KC_PAUS,
        _______, MS_BTN2, MS_BTN2, /*mouse*/                        _______,        _______,           KC_MPRV, KC_MPLY,   KC_MSTP, KC_MNXT,
                                               _______,    MS_BTN4, MS_BTN5,        _______, _______,
                                                           MS_BTN1, MS_BTN3,        _______, _______,  _______
    ),

    [_ADJUST] = LAYOUT(
        QK_GESC, QWERTY,  COLEMAK, GAMING,  VRSN,    KC_NO,   KC_NO,    QK_BOOTLOADER, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5,  KC_INT6, KC_NO,          KC_NO,   KC_LNG1, KC_LNG2, KC_LNG3, KC_LNG4, KC_LNG5,
        KC_INT7, KC_INT8, KC_INT9, KC_NO,   KC_UNDO,  KC_NO,   KC_NO,          KC_NO,   KC_LNG6, KC_AGAIN,KC_LNG7, KC_LNG8, KC_LNG9,
        _______, KC_DEL,  KC_CUT,  KC_COPY, KC_PASTE, KC_MENU, _______,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, _______, _______, /*scroll*/                  _______,        _______,          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,
                                            _______,  _______, _______,        _______, _______,
                                                      _______, _______,        _______, _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);  // if raise and lower are active, switch to adjust layer
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;

    case UC_EURO:
        send_unicode_string("€");
        return false;
    case UC_DEG:
        send_unicode_string("€");
        return false;
    // case VRSN:
      // if (record->event.pressed) {
        // SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      // }
      // return false;
      // break;
  }
  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER] = { ENCODER_CCW_CW(LCTL(KC_TAB), LCTL(LSFT(KC_TAB)))},
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

enum joystick_modes {
    JOYSTICK_MODE_WHEEL,
    JOYSTICK_MODE_STICK,
    JOYSTICK_MODE_MOUSE,
};

/* oled stuff :) */
#ifdef OLED_ENABLE
uint16_t startup_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
};

/* Display wheel or joystick icon on specified location, based on provided mode value. */
static void render_joystick_mode(uint8_t mode, uint8_t posX, uint8_t posY) {
    static const char char_map_wheel_mode [] PROGMEM = {0x9e, 0x9f, 0x00, 0xbe, 0xbf, 0x00, 0xde, 0xdf, 0x00};
    static const char char_map_joystick_mode [] PROGMEM = {0x9c, 0x9d, 0x00, 0xbc, 0xbd, 0x00, 0xdc, 0xdd, 0x00};
    static const char char_map_mouse_mode [] PROGMEM = {0x9a, 0x9b, 0x00, 0xba, 0xbb, 0x00, 0xda, 0xdb, 0x00};
    oled_set_cursor(posX, posY++);
    const char *p = (mode == JOYSTICK_MODE_WHEEL ? char_map_wheel_mode: char_map_joystick_mode);
    p = (mode == JOYSTICK_MODE_MOUSE ? char_map_mouse_mode: p);
    oled_write_P(p, false); p += 3;
    oled_set_cursor(posX, posY++);
    oled_write_P(p, false); p += 3;
    oled_set_cursor(posX, posY);
    oled_write_P(p, false);
}

/* Shows the name of the current layer and locks for the host (CAPS etc.) */
static void render_info(void) {
    static const char char_map_qwerty [] PROGMEM = {
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0x00, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0x00
    };
    static const char char_map_colemak [] PROGMEM = {
        0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0x00, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xeb, 0x00
    };
    static const char char_map_gaming [] PROGMEM = {
        0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0x00, 0xec, 0xed, 0xee, 0xef, 0xf0, 0xf1, 0x00
    };
    const char *p = (default_layer_state == (1 << _COLEMAK) ? char_map_colemak: char_map_qwerty);
    p = (default_layer_state == (1 << _GAMING) ? char_map_gaming: p);
    oled_set_cursor(0,0);
    oled_write(p, false); p += 7;
    oled_set_cursor(0,1);
    oled_write(p, false);

    char strL1[] = "      ";
    char strL2[] = "      ";
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        strL1[0] = 0x01; strL1[1] = 0x02; strL2[0] = 0x07; strL2[1] = 0x08;
    }
    if (led_state.num_lock) {
        strL1[2] = 0x03; strL1[3] = 0x04; strL2[2] = 0x09; strL2[3] = 0x0B;
    }
    if (led_state.scroll_lock) {
        strL1[4] = 0x05; strL1[5] = 0x06; strL2[4] = 0x0C; strL2[5] = 0x0D;
    }
    oled_set_cursor(0,2);
    oled_write(strL1, false);
    oled_set_cursor(0,3);
    oled_write(strL2, false);

    oled_set_cursor(10,0);
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QWERTY:
        case _COLEMAK:
        case _GAMING:
            oled_write_P(PSTR("BASE  "), false);
            render_joystick_mode(JOYSTICK_MODE_WHEEL, 7, 1);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("NUMPAD"), false);
            render_joystick_mode(JOYSTICK_MODE_WHEEL, 7, 1);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER "), false);
            render_joystick_mode(JOYSTICK_MODE_WHEEL, 7, 1);
           break;
        case _RAISE:
            oled_write_P(PSTR("RAISE "), false);
            render_joystick_mode(JOYSTICK_MODE_MOUSE, 7, 1);
            break;
        default:
            oled_write_P(PSTR("ADJUST"), false);
            render_joystick_mode(JOYSTICK_MODE_WHEEL, 7, 1);
    }
}


bool oled_task_user(void) {
    if (! is_keyboard_master())
        return false;
    render_info();
    return false;
}
#endif


enum nubbin_modes {
    _SCROLLING,
    _CURSOR,
    _TAPPING
};

uint8_t determine_nubbin_mode(void) {
    /* Returns operation mode of the nubbin (joystick) based on the currently selected layer. */
    uint8_t layer = get_highest_layer(layer_state);
    if (layer == _RAISE) {
        return _CURSOR;
    }
    return _SCROLLING;
}

/* Pointing device code shamelessly nabbed from /keyboards/edinburgh41 */

// Thumbstick keymap, change KC_XXX to whatever you need
#define THUMBSTICK_RIGHT_TAP KC_RIGHT
#define THUMBSTICK_LEFT_TAP KC_LEFT
#define THUMBSTICK_UP_TAP KC_UP
#define THUMBSTICK_DOWN_TAP KC_DOWN

// tracks if thumbstick was released
bool returned_to_zero = true;

// tracks how many times mouse_report.x/y have been read zero in succession
uint16_t zero_reads = 0;

// manipulate mouse report based on current mode
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (! is_keyboard_master())
        return mouse_report;
    switch (determine_nubbin_mode()) {
      case _CURSOR:
        mouse_report.x = CURSOR_SPEED * mouse_report.x/100;
        mouse_report.y = CURSOR_SPEED * mouse_report.y/100;
        break;
      case _SCROLLING:
        mouse_report.h = SCROLL_SPEED * mouse_report.x/100;
        mouse_report.v = - SCROLL_SPEED * mouse_report.y/100;  // inverted Y-axis just for scrolling
        mouse_report.x = 0;
        mouse_report.y = 0;
        if ((mouse_report.h != 0) | (mouse_report.v != 0)) {
            wait_ms(SCROLL_DELAY_MS);
        }
        break;
      case _TAPPING: // NOT USED
        if ((mouse_report.x || mouse_report.y) != 0) {
            if (returned_to_zero) {
                if (mouse_report.x > 0) {
                    tap_code16(THUMBSTICK_RIGHT_TAP);
                }
                if (mouse_report.x < 0) {
                    tap_code16(THUMBSTICK_LEFT_TAP);
                }
                if (mouse_report.y > 0) {
                    tap_code16(THUMBSTICK_DOWN_TAP);
                }
                if (mouse_report.y < 0) {
                    tap_code16(THUMBSTICK_UP_TAP);
                }
                returned_to_zero = false;
            }
            zero_reads = 0;
        } else if (zero_reads < 20) {
            zero_reads++;
        }
        if (zero_reads >= 20) {
            if (returned_to_zero == false) {
                returned_to_zero = true;
            }
        }
        mouse_report.x = 0;
        mouse_report.y = 0;
        break;
    }

    return mouse_report;
}


// int16_t xcen, ycen;  // center values for joystick axes

// void keyboard_post_init_user(void) {
//     joystick_read_axes();
//     xcen = joystick_state.axes[0];
//     ycen = joystick_state.axes[1];
//     uprintf("Joystick center @ %d, %d\n", xcen, ycen);
// }
