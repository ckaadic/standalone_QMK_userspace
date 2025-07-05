#pragma once

// Common QMK settings
#define USB_SUSPEND_WAKEUP_DELAY 2000
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1500U
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// Space saving options
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
// Tap-hold settings
#define TAPPING_TERM 230
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Input intervals
#define QUICK_TAP_TERM TAPPING_TERM - 100
#define SHIFT_TAP_TERM TAPPING_TERM - 60
#define COMBO_IDLE_MS  TAPPING_TERM + 100
#define INPUT_IDLE_MS  TAPPING_TERM - 80

#ifdef COMBO_ENABLE
#   define COMBO_TERM 25
#   define EXTRA_SHORT_COMBOS
#   define COMBO_SHOULD_TRIGGER
#endif

#ifdef SPLIT_KEYBOARD
#   define EE_HANDS
#endif

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif