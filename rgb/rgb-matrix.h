// Copyright 2022 @filterpaper
// SPDX-License-Identifier: GPL-2.0+

#pragma once
#include QMK_KEYBOARD_H

// Dimmer RGB colors
#define RGB_BSTEEL	55, 80, 115
#define RGB_DPURPLE	60, 0, 115
#define RGB_DPINK	115, 20, 45
#define RGB_DTEAL	5, 35, 35
#define RGB_FLUOR	75, 122, 22

// Custom definitions
#ifdef KEYBOARD_reviung_reviung34
#   define RGB_DI_PIN D3
#	define RGBLED_NUM 9
#endif

#define RGBLIGHT_EFFECT_BREATHING