#include "ckaadic.h"


#ifdef TAPPING_TERM_PER_KEY
#	define IS_TYPING() (timer_elapsed(tap_timer) < TAPPING_TERM * 1.3)
static uint16_t tap_timer = 0;
// Increase tapping term in between short key presses to avoid false trigger.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
	return MODTAP_BIT(keycode) & MOD_MASK_CAG && IS_TYPING() ? TAPPING_TERM * 1.3 : TAPPING_TERM;
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
// Select Shift mod tap immediately when another key is pressed and released.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
	return keycode == RSFT_T(KC_SPC) ? true : false;
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// Select hold immediately with another key for layer tap 1 and higher.
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	return IS_LAYER_TAP(keycode) ? true : false;
}
#endif

#ifdef TAPPING_FORCE_HOLD_PER_KEY
// Force hold on tap-hold key when held after tapping,
// enable for (right split) bottom row key.
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	return record->event.key.row == MATRIX_ROWS - 1 ? true : false;
}
#endif


// Send custom hold keycode for mod tap.
static inline bool process_tap_hold(uint16_t hold_keycode, keyrecord_t *record) {
	if (!record->tap.count) {
		tap_code16(hold_keycode);
		return false;
	}
	return true;
}


bool process_record_user(uint16_t const keycode, keyrecord_t *record) {
	if (record->event.pressed) {
#ifdef TAPPING_TERM_PER_KEY
		tap_timer = timer_read();
#endif
#ifdef AUTO_CORRECT
		extern bool process_autocorrect(uint16_t keycode, keyrecord_t* record);
		if (!process_autocorrect(keycode, record)) {
			return false;
		}
#endif
	}
	return true;
}


bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case M_AE:
            if (record->event.pressed) {
                SEND_STRING("\"a");
            }
            return false;
        case M_OE:
            if (record->event.pressed) {
                SEND_STRING("\"o");
            }
            return false;
        case M_UE:
            if (record->event.pressed) {
                SEND_STRING("\"u");
            }
            return false;
    }
    return process_record_user(keycode, record);
};
