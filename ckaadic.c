#include "ckaadic.h"





// Send custom hold keycode for mod tap.
static inline bool process_tap_hold(uint16_t hold_keycode, keyrecord_t *record) {
	if (!record->tap.count) {
		tap_code16(hold_keycode);
		return false;
	}
	return true;
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t const keycode, keyrecord_t *record) {
	switch (keycode) {
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