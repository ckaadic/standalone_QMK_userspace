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

// Layout macros
#ifndef __ASSEMBLER__
#   include "layout.h"
#endif