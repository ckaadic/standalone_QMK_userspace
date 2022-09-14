#pragma once

#include "keymaps/layout.h"

// Common QMK variables
#define TAPPING_TERM 250
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM_PER_KEY
#define TAP_CODE_DELAY 5
#define TAP_HOLD_CAPS_DELAY 25

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

#ifdef QMK_MCU_FAMILY_RP
#	define SPLIT_USB_TIMEOUT 2000
#	define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U
#endif

#ifdef KEYBOARD_reviung_reviung34
#elseif OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_OLED_ENABLE
    #define OLED_TIMEOUT 60000
    #define OLED_FONT_H "oled/glcdfont.c"
#endif

#ifdef KEYBOARD_reviung_reviung34
#   define RGB_DI_PIN D3
//#   define DRIVER_LED_TOTAL 9
#	define RGBLED_NUM 9
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_SLEEP
#endif