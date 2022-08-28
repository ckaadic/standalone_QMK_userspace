#include "ckaadic.h"
#include "config.h"


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
	switch (keycode) {
        case M_AE:
            if (record->event.pressed) {
                SEND_STRING("\"a");
            }
            break;
        case M_OE:
            if (record->event.pressed) {
                SEND_STRING("\"o");
            }
            break;
        case M_UE:
            if (record->event.pressed) {
                SEND_STRING("\"u");
            }
            break;
  }
	return true;
}


const key_override_t lbracket_override = {.trigger_mods          = MOD_MASK_SHIFT,
                                   .layers                 = ~0,
                                   .suppressed_mods        = MOD_MASK_SHIFT,
                                   .options                = ko_options_default,
                                   .trigger                = KC_LBRACKET,
                                   .replacement            = KC_RBRACKET,
                                   .enabled                = NULL};

const key_override_t hbracket_override = {.trigger_mods          = MOD_MASK_SHIFT,
                                   .layers                 = ~0,
                                   .suppressed_mods        = MOD_MASK_SHIFT,
                                   .options                = ko_options_default,
                                   .trigger                = LSFT(KC_LBRACKET),
                                   .replacement            = LSFT(KC_RBRACKET),
                                   .enabled                = NULL};

const key_override_t bracket_override = ko_make_basic(MOD_MASK_SHIFT, LSFT(KC_9), LSFT(KC_0));

const key_override_t **key_overrides = (const key_override_t *[]){
    //&backspace_override,
    &lbracket_override,
    &hbracket_override,
    &bracket_override,
    NULL
};