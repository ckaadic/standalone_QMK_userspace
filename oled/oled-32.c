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
        0xff, 0x01, 0x01, 0xf1, 0xf1, 0x01, 0x01, 0x71, 0x71, 0x01, 0x01, 0xff, 0x31, 0x31, 0x11, 0x11, 
0x91, 0xc1, 0xc1, 0xe1, 0xe1, 0xe1, 0xff, 0xff, 0xfb, 0xfb, 0xfb, 0xff, 0xdf, 0xdf, 0xdf, 0xdf, 
0xdf, 0xdf, 0xdf, 0xdd, 0xfd, 0xff, 0xff, 0xfd, 0x7d, 0x7d, 0x7d, 0x65, 0x75, 0xc7, 0xcd, 0xcd, 
0xcd, 0x8d, 0x8d, 0x8d, 0x0d, 0x09, 0x09, 0x09, 0x01, 0x81, 0x41, 0x01, 0x01, 0x01, 0x09, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x09, 0x09, 0x01, 0x01, 0x81, 0x81, 0x81, 0x03, 0x03, 0x03, 0x03, 0x03, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 
0x07, 0x87, 0xc7, 0xc7, 0xc7, 0xc7, 0xc7, 0xe7, 0xe7, 0xe7, 0x67, 0x67, 0x67, 0x67, 0xe7, 0x27, 
0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xef, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xc6, 0xc8, 0x08, 0x08, 0x9c, 0x1e, 0x3c, 0x3c, 0x3c, 0x7e, 0xff, 0x23, 0x63, 0xe2, 0xe2, 
0xe2, 0xe0, 0xe0, 0xe1, 0xe1, 0x61, 0xfd, 0xfd, 0xfd, 0x7d, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
0xfd, 0xfd, 0xff, 0xff, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0xe3, 
0xe3, 0xa1, 0xe1, 0xe1, 0x00, 0x00, 0x00, 0xc2, 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 0x00, 0x80, 
0x88, 0x0a, 0x00, 0x80, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7c, 0x7c, 0x7c, 0xff, 0x7c, 
0xff, 0x7c, 0x7c, 0x7c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0x07, 0x03, 0x00, 0x10, 0x11, 0x11, 0x19, 0x18, 0x1c, 0x1c, 0xfd, 0x3c, 0x1c, 0x88, 0x81, 
0xc3, 0xe3, 0xc1, 0x88, 0x18, 0x1c, 0xff, 0xff, 0xdf, 0xdf, 0xdf, 0xff, 0xdf, 0xff, 0xff, 0xff, 
0xfe, 0xfe, 0xfe, 0xf6, 0xf6, 0xf6, 0xfe, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0x32, 0x32, 
0x3b, 0xb3, 0x20, 0x20, 0x42, 0x40, 0x04, 0x04, 0x00, 0x00, 0x80, 0x00, 0x04, 0x40, 0x08, 0x80, 
0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x01, 0x03, 0x07, 0x06, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0d, 0x0c, 0x0c, 0x8c, 0x8f, 0x88, 
0x8f, 0xce, 0xce, 0xce, 0xcf, 0xcf, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xf0, 0xc0, 0xc7, 0x8f, 0x8f, 0x8f, 0x8f, 0xc7, 0xc0, 0xf0, 0xf7, 0xf6, 0xff, 0xbf, 0xbf, 
0xbf, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf7, 0xf7, 0xf7, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xbf, 0xbe, 0xbe, 0xfe, 0xfe, 0xde, 0xde, 0xde, 0x9b, 0x9b, 0x9b, 0xbf, 0x88, 0x88, 
0x89, 0x81, 0x81, 0x81, 0x80, 0xa1, 0xa1, 0xa1, 0x80, 0x80, 0x80, 0x80, 0x81, 0x81, 0x80, 0x80, 
0x80, 0x84, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 
0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    };
    oled_write_P(raw_logo, sizeof(raw_logo));
}


oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_0;
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