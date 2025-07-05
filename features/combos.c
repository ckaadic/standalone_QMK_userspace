#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "print.h"

// Combo functions
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    return true;
}

bool combo_should_trigger(
        uint16_t combo_index,
        combo_t *combo,
        uint16_t keycode,
        keyrecord_t *record
    ) {
    return true;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    return 60;
}