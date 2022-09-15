#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE

char layer_state_str[24];
char o_text[24] = "";

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _CANARY:
            strcpy ( layer_state_str, " CAN ");
            break;
        case _QWERTY:
            strcpy ( layer_state_str, " QWE ");
            break;
        case _COLE:
            strcpy ( layer_state_str, " COL ");
            break;
        case _LOWER:
            strcpy ( layer_state_str, "LOWER");
            break;
        case _RAISE:
            strcpy ( layer_state_str, "RAISE");
            break;
        case _ADJUST:
            strcpy ( layer_state_str, " ADJ ");
            break;
        default:
            strcpy ( layer_state_str, "XXXXX");
    }
    strcpy ( o_text, layer_state_str );
  //return state;
    return update_tri_layer_state(state, 2, 3, 4);
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {  // ────────────────────────── PRIMARY SIDE
        oled_write_ln(o_text, false);
        //render_os_lock_status();

    } else {  // ─────────────────────────────────────────── SECONDARY SIDE
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE