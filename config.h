#pragma once

// Common QMK settings
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1500U
//#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Space saving options
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
// Tap-hold settings
#define TAPPING_TERM 210
#define TAPPING_TERM_PER_KEY
//#define PERMISSIVE_HOLD_PER_KEY
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define COMBO_TERM 35
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
// #define COMBO_ONLY_FROM_LAYER 0
#define COMBO_SHOULD_TRIGGER
#define COMBO_MUST_HOLD_MODS 


#ifdef SPLIT_KEYBOARD
#   define EE_HANDS
#endif

#ifdef OLED_ENABLE
#   define OLED_TIMEOUT 10000
#   define OLED_BRIGHTNESS 180
#   define OLED_FONT_H "oled_font.c"
#endif

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES
#   define RGB_MATRIX_DEFAULT_SPD 208
#   define RGB_MATRIX_DEFAULT_HUE 180
#   define ENABLE_RGB_MATRIX_CUSTOM_CANDY_TAP
#   define ENABLE_RGB_MATRIX_CUSTOM_PIXEL_MOSAIC
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CUSTOM_CANDY_TAP
#   define DEF_MODE RGB_MATRIX_CUSTOM_CANDY_TAP
#   define CMK_MODE RGB_MATRIX_CUSTOM_PIXEL_MOSAIC
#endif

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif