#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE

char layer_state_str[24];
char o_text[24] = "";

layer_state_t layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0:
            strcpy ( layer_state_str, " CAN ");
            break;
        case 1:
            strcpy ( layer_state_str, " QWE ");
            break;
        case 2:
            strcpy ( layer_state_str, "LOWER");
            break;
        case 3:
            strcpy ( layer_state_str, "RAISE");
            break;
        case 4:
            strcpy ( layer_state_str, " ADJ ");
            break;
        default:
            strcpy ( layer_state_str, "XXXXX");
    }
    strcpy ( o_text, layer_state_str );
  //return state;
    return update_tri_layer_state(state, 2, 3, 4);
}

void corne_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

static void mxbad_render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        255,  1,  1,241,241,  1,  1,113,113,  1,  1,255, 49, 49, 17, 17,145,193,193,225,225,225,255,255,251,251,251,255,223,223,223,223,223,223,223,221,253,255,255,253,125,125,125,101,117,199,205,205,205,141,141,141, 13,  9,  9,  9,  1,129, 65,  1,  1,  1,  9,  1,  1,  1,  1,  1,  9,  9,  1,  1,129,129,129,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  7,  7,  7,  7,135,199,199,199,199,199,231,231,231,103,103,103,103,231, 39,231,231,231,231,231,239,207,159,
        63,127,255,255,255,255,255,255,255,198,200,  8,  8,156, 30, 60, 60, 60,126,255, 35, 99,226,226,226,224,224,225,225, 97,253,253,253,125,127,127,127,255,255,255,253,253,255,255,223,223,255,255,255,255,223,223,223,223,223,227,227,161,225,225,  0,  0,  0,194,  0,  0,128,  0, 64,  0,  0,128,136, 10,  0,128,  0,  4, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255, 
        0,255,255,255,255,255,255,255,124,124,124,255,124,255,124,124,124,255,255,255,255,255,  0,  0,255,255,255,255,255,255,  7,  3,  0, 16, 17, 17, 25, 24, 28, 28,253, 60, 28,136,129,195,227,193,136, 24, 28,255,255,223,223,223,255,223,255,255,255,254,254,254,246,246,246,254,246,246,246,246,246,246,246, 50, 50, 59,179, 32, 32, 66, 64,  4,  4,  0,  0,128,  0,  4, 64,  8,128,128,  0,  0, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7, 
        6,  7,  7,  7, 15, 15, 15, 13, 12,
        
        55,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}


oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION
        //return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
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
        mxbad_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE