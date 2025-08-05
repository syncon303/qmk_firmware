// Copyright 2024 Hyojin Bak (@eerraa)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Split configuration */
/* uses PIO driver */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP1
#define SERIAL_USART_RX_PIN GP0

#undef SERIAL_USART_PIN_SWAP
// swap pins for master; required if both halves have exact same TRRS connector wiring
// #define SERIAL_USART_PIN_SWAP

/* OLED */
#define I2C1_SCL_PIN  GP19
#define I2C1_SDA_PIN  GP18
#define I2C_DRIVER I2CD1
#define I2C1_CLOCK_SPEED 400000
#define OLED_BRIGHTNESS 128
#define OLED_TIMEOUT 600000
#define OLED_SCROLL_TIMEOUT 300000
/* Oled Size */
#define OLED_DISPLAY_128X32
#define OLED_FONT_END 255
#define OLED_FONT_H "gfxfont.c"

/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

/* Joystick axis deadband */
#define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP27
#define ANALOG_JOYSTICK_WEIGHTS {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,28,29,29,30,31,33,34,35,36,37,40,41,43,44,48,49,51,56,58,60,65,68,70,73,79,82,85,89,96,100,100,100,100,100,100}

#ifndef CURSOR_SPEED
    #define CURSOR_SPEED 100
#endif
#ifndef SCROLL_SPEED
    #define SCROLL_SPEED 25
#endif
#ifndef SCROLL_DELAY_MS
    #define SCROLL_DELAY_MS 70
#endif

#define POINTING_DEVICE_HIRES_SCROLL_ENABLE
#define WHEEL_EXTENDED_REPORT
