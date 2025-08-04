// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum planka_layers {
  _QWERTY,
  _COLEMAK,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
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
    [_QWERTY] = LAYOUT_split_6x7_6x6(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_RCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MINS,        KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,        KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_RCTL, KC_LGUI, KC_APP,                             KC_GRV,         KC_TAB,           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_DEL,  KC_LSFT, KC_LALT,        KC_RALT, KC_RSFT,
                                                     KC_SPC,  KC_LCTL,        KC_RCTL, KC_ENT,  KC_BSPC
    ),
    [_COLEMAK] = LAYOUT_split_6x7_6x6(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,        KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_LBRC,        KC_RBRC, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_RCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_MINS,        KC_EQL,  KC_H,    KC_N,    KC_E,    KC_I,    KC_O,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOT,        KC_BSLS, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        KC_RCTL, KC_LGUI, KC_APP,                             KC_GRV,         KC_TAB,           KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,
                                            KC_DEL,  KC_LSFT, KC_LALT,        KC_RALT, KC_RSFT,
                                                     KC_SPC,  KC_LCTL,        KC_RCTL, KC_ENT,  KC_BSPC
    ),
    [_NUMPAD] = LAYOUT_split_6x7_6x6(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,        KC_NUM,  KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9,   KC_KP_SLASH,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6,   KC_KP_ASTERISK,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3,   KC_KP_MINUS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_KP_0, KC_NO,   KC_KP_DOT, KC_KP_PLUS,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,        KC_TRNS,          KC_MPRV, KC_MPLY, KC_MSTP,   KC_MNXT,
                                            KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),


    [_LOWER] = LAYOUT_split_6x7_6x6(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,          KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F7,   KC_F8,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_MINS, KC_EQL,  UNDERS,  PLUS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC),
        KC_TRNS, KC_DEL,  KC_CUT,  KC_COPY, KC_PASTE, KC_MENU, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS,        KC_TRNS,          KC_HOME, KC_PGDN, KC_PGUP,       KC_END,
                                            KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                      KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),


    [_RAISE] = LAYOUT_split_6x7_6x6(
        KC_F13,  KC_F14,  KC_F15,  KC_F16,        KC_F17,        KC_F18,  KC_TRNS,        KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,   KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_NO,   KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_DEL,  KC_CUT,  KC_COPY,       KC_PASTE,      KC_MENU, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS,        KC_TRNS,          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,
                                                  KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_ADJUST] = LAYOUT_split_6x7_6x6(
        KC_F13,  KC_F14,  KC_F15,  KC_F16,        KC_F17,        KC_F18,  KC_TRNS,        KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,         KC_F5,         KC_F6,   KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LBRC, KC_RBRC, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_NO,   KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_DEL,  KC_CUT,  KC_COPY,       KC_PASTE,      KC_MENU, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS,        KC_TRNS,          KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT,
                                                  KC_TRNS,       KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_COLEMAK] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_NUMPAD] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LOWER] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_RAISE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_ADJUST] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
};
#endif

/* oled stuff :) */
#ifdef OLED_ENABLE
uint16_t startup_timer;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
}
// 'icon_capslock', 16x16px
const unsigned char epd_bitmap_icon_capslock [] PROGMEM = {
	0x80, 0x03, 0x00, 0x01, 0x3f, 0xf9, 0x38, 0x39, 0x38, 0x39, 0x33, 0x99, 0x33, 0x99, 0x33, 0x99,
	0x30, 0x19, 0x30, 0x19, 0x33, 0x99, 0x33, 0x99, 0x3f, 0xf9, 0x00, 0x01, 0x80, 0x03, 0xff, 0xff
};
// 'icon_numlock', 16x16px
const unsigned char epd_bitmap_icon_numlock [] PROGMEM = {
	0x80, 0x03, 0x00, 0x01, 0x3f, 0xf9, 0x38, 0x79, 0x38, 0x79, 0x3e, 0x79, 0x3e, 0x79, 0x3e, 0x79,
	0x3e, 0x79, 0x3e, 0x79, 0x3e, 0x79, 0x3e, 0x79, 0x3f, 0xf9, 0x00, 0x01, 0x80, 0x03, 0xff, 0xff
};
// 'icon_scrolllock', 16x16px
const unsigned char epd_bitmap_icon_scrolllock [] PROGMEM = {
	0x80, 0x03, 0x00, 0x01, 0x3f, 0xf9, 0x3c, 0x79, 0x3c, 0x79, 0x3c, 0x79, 0x3c, 0x79, 0x3c, 0x79,
	0x30, 0x19, 0x38, 0x39, 0x3c, 0x79, 0x3e, 0xf9, 0x3f, 0xf9, 0x00, 0x01, 0x80, 0x03, 0xff, 0xff
};
const unsigned char epd_bitmap_icon_blank [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 144)
const int epd_bitmap_allArray_LEN = 3;
const unsigned char* epd_bitmap_allArray[3] = {
	epd_bitmap_icon_capslock,
	epd_bitmap_icon_numlock,
	epd_bitmap_icon_scrolllock
};

/* Shows the name of the current layer and locks for the host (CAPS etc.) */
static void render_info(void) {

    led_t led_state = host_keyboard_led_state();
    char strL1[7] = "      \0";
    char strL2[7] = "      \0";
    // strL1[7] = \0; strL2[7] = \0;
    if (led_state.caps_lock) {
        strL1[0] = 0x80; strL1[1] = 0x81; strL2[0] = 0xA0; strL2[1] = 0xA1;
    }
    if (led_state.num_lock) {
        strL1[0] = 0x82; strL1[1] = 0x83; strL2[0] = 0xA2; strL2[1] = 0xA3;
    }
    if (led_state.scroll_lock) {
        strL1[0] = 0x84; strL1[1] = 0x85; strL2[0] = 0xA4; strL2[1] = 0xA5;
    }
    oled_set_cursor(0,0);
    oled_write(strL1, false);
    oled_set_cursor(0,1);
    oled_write(strL2, false);
    char strL3[5] = "    \0";
    char strL4[5] = "    \0";
    if (default_layer_state == _QWERTY) {
        strL3[1] = 0x86; strL3[2] = 0x87; strL4[1] = 0xA6; strL4[2] = 0xA7;
    }
    else {
        strL3[1] = 0x88; strL3[2] = 0x89; strL4[1] = 0xA8; strL4[2] = 0xA9;
    }
    oled_set_cursor(0,2);
    oled_write(strL3, false);
    oled_set_cursor(0,3);
    oled_write(strL4, false);

    oled_set_cursor(8,0);
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("HOME"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLE"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMP"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWR"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAIS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UPPR"), false);
    }
    oled_set_cursor(8,1);
    oled_write_P(PSTR("D.lay: "), false);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("HOME"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLE"), false);
            break;
        case _NUMPAD:
            oled_write_ln_P(PSTR("NUMP"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOWR"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("RAIS"), false);
            break;
        default:
            oled_write_ln_P(PSTR("UPPR"), false);
    }
}

bool oled_task_user(void) {
    render_info();
    return false;
}
#endif
