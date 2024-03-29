#include "ckaadic.h"
#include "config.h"

// Layers
#define LOWER 2
#define RAISE 3
#define ADJUST 4

void keyboard_post_init_user(void) {
  // Call the post init code.
  #if HAPTIC_ENABLE
    haptic_disable(); // disables per key haptic feedback by default
  #endif //HAPTIC ENABLE
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_T):
            return TAPPING_TERM - 150;
        case LSFT_T(KC_N):
            return TAPPING_TERM - 150;
        default:
            return TAPPING_TERM;
    }
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
        case LOWER:
            if (record->event.pressed) {
                layer_on(LOWER);
                update_tri_layer(LOWER, RAISE, ADJUST);
            } else {
                layer_off(LOWER);
                update_tri_layer(LOWER, RAISE, ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(RAISE);
                update_tri_layer(LOWER, RAISE, ADJUST);
            } else {
                layer_off(RAISE);
                update_tri_layer(LOWER, RAISE, ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(ADJUST);
            } else {
                layer_off(ADJUST);
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

#ifdef ENCODER_ENABLE

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  L                                          │
// └───────────────────────────────────────────────────────────┘

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      if(IS_LAYER_ON(LOWER)){
          if (clockwise) {
              tap_code16(C(KC_TAB));
          } else {
              tap_code16(C(S(KC_TAB)));
          }
      }else if(IS_LAYER_ON(RAISE)){
        if(clockwise){
          tap_code(KC_WH_R);
        }
        else{
          tap_code(KC_WH_L);
        }
      }else{
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
      }

// ┌───────────────────────────────────────────────────────────┐
// │ e n c o d e r  R                                          │
// └───────────────────────────────────────────────────────────┘

    } else if (index == 1) {
      if(IS_LAYER_ON(LOWER)){
          if (clockwise) {
              tap_code16(C(KC_Y));
          } else {
              tap_code16(C(KC_Z));
          }
      }else if(IS_LAYER_ON(RAISE)){
        if(clockwise){
          tap_code(KC_WH_D);
        }
        else{
          tap_code(KC_WH_U);
        }
      }else {
            if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      }
    }
    return true;
}

#endif // ENCODER_ENABLE