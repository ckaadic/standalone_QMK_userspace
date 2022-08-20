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

#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_KEYPRESSES
#  define RGB_DISABLE_WHEN_USB_SUSPENDED true
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
#endif

#ifdef OLED_ENABLE
#	define OLED_TIMEOUT 10000
#	define OLED_BRIGHTNESS 180
#	define OLED_FONT_H "oled/oledfont.c"
#endif