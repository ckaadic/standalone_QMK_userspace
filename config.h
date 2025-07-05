#pragma once

// Common QMK variables
#define TAPPING_TERM 250
//#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM_PER_KEY
//#define TAP_CODE_DELAY 5
//#define TAP_HOLD_CAPS_DELAY 25
//#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
//#define TAPPING_FORCE_HOLD_PER_KEY

// Input intervals
#define QUICK_TAP_TERM TAPPING_TERM - 100
#define SHIFT_TAP_TERM TAPPING_TERM - 60
#define COMBO_IDLE_MS  TAPPING_TERM + 100
#define INPUT_IDLE_MS  TAPPING_TERM - 80


#ifdef QMK_MCU_FAMILY_RP
    #define SPLIT_USB_TIMEOUT 2000
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1500U
#endif

#ifdef SPLIT_KEYBOARD
#   define EE_HANDS
#endif

#ifdef COMBO_ENABLE
#   define COMBO_TERM 25
#   define EXTRA_SHORT_COMBOS
#   define COMBO_SHOULD_TRIGGER
#   define COMBO_ONLY_FROM_LAYER 0
#endif

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif