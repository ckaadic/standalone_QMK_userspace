// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
//#include "oled-32.h"

#define BSE 0
#define QWT 1
#define NUM 2
#define SYM 3
#define FNC 4



oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void render_layer_symbol(void) {
    static const char PROGMEM default_layer[] = {
        0x20, 0x94, 0x95, 0x96, 0x20,
        0x20, 0xb4, 0xb5, 0xb6, 0x20,
        0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
    static const char PROGMEM sym_layer[] = {
        0x20, 0x97, 0x98, 0x99, 0x20,
        0x20, 0xb7, 0xb8, 0xb9, 0x20,
        0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
    static const char PROGMEM num_layer[] = {
        0x20, 0x9a, 0x9b, 0x9c, 0x20,
        0x20, 0xba, 0xbb, 0xbc, 0x20,
        0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
    static const char PROGMEM fun_layer[] = {
        0x20, 0x9d, 0x9e, 0x9f, 0x20,
        0x20, 0xbd, 0xbe, 0xbf, 0x20,
        0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
    if(layer_state_is(FNC)) {
        oled_write_P(fun_layer, false);
    } else if(layer_state_is(NUM)) {
        oled_write_P(num_layer, false);
    } else if(layer_state_is(SYM)) {
        oled_write_P(sym_layer, false);
    } else {
        oled_write_P(default_layer, false);
    }
}

void render_layer_name(void) {
   switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            oled_write_P(PSTR(" CAN "), false);
            break;
        case 1:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case 2:
            oled_write_P(PSTR(" NUM "), false);
            break;
        case 3:
            oled_write_P(PSTR(" SYM "), false);
            break;
        case 4:
            oled_write_P(PSTR(" FUN "), false);
            break;
        default:
            oled_write_P(PSTR("XXXXX"), false);
    }
}

void render_mod_state(uint8_t modifiers) {
    static const char PROGMEM shift_line_1[] = {
        0x85, 0x86, 0x87, 0};
    static const char PROGMEM shift_line_2[] = {
        0xa5, 0xa6, 0xa7, 0};

    static const char PROGMEM ctrl_line_1[] = {
        0x88, 0x89, 0x8a, 0x8b, 0};
    static const char PROGMEM ctrl_line_2[] = {
        0xa8, 0xa9, 0xaa, 0xab, 0};

    static const char PROGMEM os_line_1[] = {
        0x8c, 0x8d, 0x8e, 0};
    static const char PROGMEM os_line_2[] = {
        0xac, 0xad, 0xae, 0};

    static const char PROGMEM alt_line_1[] = {
        0x8f, 0x90, 0x91, 0};
    static const char PROGMEM alt_line_2[] = {
        0xaf, 0xb0, 0xb1, 0};

    if (modifiers & MOD_MASK_GUI) {
        oled_write(" ", false);
        oled_write_ln_P(os_line_1, false);
        oled_write(" ", false);
        oled_write_ln_P(os_line_2, false);
    } else {
        oled_write_ln("", false);
        oled_write_ln("", false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write(" ", false);
        oled_write_ln_P(shift_line_1, false);
        oled_write(" ", false);
        oled_write_ln_P(shift_line_2, false);
    } else {
        oled_write_ln("", false);
        oled_write_ln("", false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write(" ", false);
        oled_write_ln_P(alt_line_1, false);
        oled_write(" ", false);
        oled_write_ln_P(alt_line_2, false);
    } else {
        oled_write_ln("", false);
        oled_write_ln("", false);
    }

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_ln_P(ctrl_line_1, false);
        oled_write_ln_P(ctrl_line_2, false);
    } else {
        oled_write_ln("", false);
        oled_write_ln("", false);
    }
}

void render_status(void){
    render_layer_name();

    render_layer_symbol();

    oled_write_P(PSTR("\n\n\n"), false);

    render_mod_state(get_mods()|get_oneshot_mods());
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,  0};
    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    //render_status();
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}
