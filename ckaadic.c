#include QMK_KEYBOARD_H

// Convert 5-bit to 8-bit packed modifiers
#define MOD_TAP_GET_MOD_BITS(k) (((k) & 0x0f00) >> (((k) & 0x1000) ? 4 : 8))
// Basic keycode filter for tap-hold keys
#define GET_TAP_KEYCODE(k) ((k) & 0xff)

// Tap-hold decision helper macros
#define IS_LAYER_TAP(k) (IS_QK_LAYER_TAP(k) && QK_LAYER_TAP_GET_LAYER(k))
#define IS_SHORTCUT(k) (IS_QK_LAYER_TAP(k) && !QK_LAYER_TAP_GET_LAYER(k))
#define IS_MOD_TAP_SHIFT(k) (IS_QK_MOD_TAP(k) && (k) & QK_LSFT)
#define IS_MOD_TAP_CAG(k) (IS_QK_MOD_TAP(k) && (k) & (QK_LCTL|QK_LALT|QK_LGUI))

#define IS_HOMEROW(r) (r->event.key.row == 1 || r->event.key.row == 5)
#define IS_HOMEROW_SHIFT(k, r) (IS_HOMEROW(r) && IS_MOD_TAP_SHIFT(k))
#define IS_HOMEROW_CAG(k, r) (IS_HOMEROW(r) && IS_MOD_TAP_CAG(k))

#define IS_TYPING(k) ( \
    ((uint8_t)(k) <= KC_Z || IS_SHORTCUT(k)) && \
    (last_input_activity_elapsed() < INPUT_IDLE_MS))

#define IS_UNILATERAL(r, n) ( \
    (r->event.key.row == 1 && 0 <= n.event.key.row && n.event.key.row <= 2) || \
    (r->event.key.row == 5 && 4 <= n.event.key.row && n.event.key.row <= 6) )

#define IS_UNILATERAL_AND_NOT_SHIFT(r, c) ( \
    IS_UNILATERAL(r, c.record) && !IS_MOD_TAP_SHIFT(c.keycode))

// Contextual input storage
static struct {
    uint_fast16_t keycode;
    keyrecord_t   record;
} context;
/*
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // If the tap-hold key overlaps with another non-Shift key on the same
    // hand or if the key is a shortcut overlapping with any other key,
    // clear its interrupted state and process the tap-hold key as a tap
    if (IS_UNILATERAL_AND_NOT_SHIFT(record, context) || IS_SHORTCUT(keycode)) {
        record->tap.interrupted = false;
        record->tap.count++;
        process_record(record);
        return false;
    }
    // Activate layer hold with another key press
    else return IS_LAYER_TAP(keycode);
}


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Register Shift with a nested key press
    return IS_HOMEROW_SHIFT(keycode, record);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // Shorten interval for Shift
    return IS_HOMEROW_SHIFT(keycode, record) ? SHIFT_TAP_TERM : TAPPING_TERM;
}
*/
// Reduce marix scanning delay
#ifndef DIRECT_PINS
void matrix_io_delay(void) { __asm__ volatile("nop\nnop\nnop\n"); }
#endif