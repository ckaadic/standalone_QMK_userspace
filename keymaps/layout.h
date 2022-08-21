// Home row mod-tap macros
#define HRML(k1,k2,k3,k4) LSFT_T(k1),LALT_T(k2),LCTL_T(k3),LGUI_T(k4)
#define HRMR(k1,k2,k3,k4) LGUI_T(k1),LCTL_T(k2),LALT_T(k3),LSFT_T(k4)

// One shot mods
#ifdef NO_ACTION_ONESHOT
#	define OSM_SFT KC_LSFT
#	define OSM_CTL KC_LCTL
#	define OSM_ALT KC_LALT
#	define OSM_GUI KC_LGUI
#else
#	define OSM_SFT OSM(MOD_LSFT)
#	define OSM_CTL OSM(MOD_LCTL)
#	define OSM_ALT OSM(MOD_LALT)
#	define OSM_GUI OSM(MOD_LGUI)
#endif


// Layers
#define BSE 0
#define QWE 1
#define NUM 2
#define SYM 3
#define FNC 4


// Default 3x5_2 split layout
#define _BASE \
	KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, \
	KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    \
	KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
	                           _______, _______,     _______, _______
/* ,----------------------------------.                ,----------------------------------.
   |  Q   |  W   |  F   |  P   |  G   |                |  J   |  L   |  U   |  Y   | ' "  |
   |------+------+------+------+------|                |------+------+------+------+------|
   |  A   |  R   |  S   |  T   |  D   |                |  H   |  N   |  E   |  I   |  O   |
   |------+------+------+------+------|                |------+------+------+------+------|
   |  Z   |  X   |  C   |  V   |  B   |                |  K   |  M   | , <  | . >  | / ?  |
   `------+------+------+------+------+------.  ,------+------+------+------+------+------'
                               |      |      |  |      |      |
                               `-------------'  `-------------'
 */
#define _QWERTY \
	KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
	KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, \
	KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
	              RSA_T(KC_ESC), LT(SYM,KC_TAB),     RSFT_T(KC_SPC), LT(NUM,KC_BSPC)
/* ,----------------------------------.                ,----------------------------------.
   |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   |
   |------+------+------+------+------|                |------+------+------+------+------|
   |  A   |  S   |  D   |  F   |  G   |                |  H   |  J   |  K   |  L   | ' "  |
   |------+------+------+------+------|                |------+------+------+------+------|
   |  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  |
   `------+------+------+------+------+------.  ,------+------+------+------+------+------'
                               |_SYMB |LCA_T |  |RSFT_T|_NUMB |
                               | TAB  | ENT  |  | SPC  | BSPC |
                               `-------------'  `-------------'
 */
#define _NUMB \
	KC_INS,  KC_1,    KC_2,    KC_3,    KC_VOLU,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_COLN, \
	KC_DEL,  KC_4,    KC_5,    KC_6,    KC_VOLD,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, \
	KC_CAPS, KC_7,    KC_8,    KC_9,    KC_0,        _______, RSA_DN,  RSA_UP,  _______, _______, \
	                           MO(FNC), QK_GESC,     _______, _______
/* ,----------------------------------.                ,----------------------------------.
   | INS  |  1   |  2   |  3   | VOLU |                | HOME | PGDN | PGUP | END  |  :   |
   |------+------+------+------+------|                |------+------+------+------+------|
   | DEL  |  4   |  5   |  6   | VOLD |                | LEFT | DOWN |  UP  | RGHT |  ;   |
   |------+------+------+------+------|                |------+------+------+------+------|
   | CAPS |  7   |  8   |  9   |  0   |                |      |RSA_DN|RSA_UP|      |      |
   `------+------+------+------+------+------.  ,------+------+------+------+------+------'
                               |_FUNC | GESC |  |      |      |
                               `-------------'  `-------------'
 */
#define _SYMB \
	_______, KC_LBRC, KC_LCBR, KC_RCBR, _______,     KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD, \
	KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_ASTR, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
	_______, _______, _______, _______, _______,     KC_AMPR, KC_UNDS, KC_PLUS, KC_PIPE, _______, \
	                           _______, _______,     _______, MO(FNC)
/* ,----------------------------------.                ,----------------------------------.
   |      |  [   |  {   |  }   |      |                |  ^   |  (   |  )   |  ]   |  ~   |
   |------+------+------+------+------|                |------+------+------+------+------|
   |  !   |  @   |  #   |  $   |  %   |                |  *   |  -   |  =   |  \   |  `   |
   |------+------+------+------+------|                |------+------+------+------+------|
   |      |      |      |      |      |                |  &   |  _   |  +   |  |   |      |
   `------+------+------+------+------+------.  ,------+------+------+------+------+------'
                               |      |      |  |      |_FUNC |
                               `-------------'  `-------------'
 */
#define _FUNC \
	QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F10,      _______, KC_WH_U, KC_WH_D, _______, TG(CMK), \
	_______, KC_F4,   KC_F5,   KC_F6,   KC_F11,      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, \
	Z_SLEEP, KC_F7,   KC_F8,   KC_F9,   KC_F12,      _______, KC_BTN2, KC_BTN1, _______, Z_SSAVE, \
	                           _______, _______,     _______,	 _______
/* ,----------------------------------.                ,----------------------------------.
   |BOOT  |  F1  |  F2  |  F3  | F10  |                |      | WH_U | WH_D |      |_COLE |
   |------+------+------+------+------|                |------+------+------+------+------|
   |      |  F4  |  F5  |  F6  | F11  |                | MS_L | MS_D | MS_U | MS_R |      |
   |------+------+------+------+------|                |------+------+------+------+------|
   |SLEEP |  F7  |  F8  |  F9  | F12  |                |      | BTN2 | BTN1 |      |SSAVE |
   `------+------+------+------+------+------.  ,------+------+------+------+------+------'
                               |      |      |  |      |      |
                               `-------------'  `-------------'
 */

// 3x5_2 home row mod and tap hold wrapper
#define HRM(k) HRM_TAPHOLD(k)
#define HRM_TAPHOLD( \
	      k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, \
	      k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, \
	      k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, \
	                     k31, k32,    k33, k34 \
) \
        k01, k02, k03, k04,  k05,    k06,      k07, k08, k09, k10, \
   HRML(k11, k12, k13, k14), k15,    k16, HRMR(k17, k18, k19, k20), \
	    k21, k22, k23, k24,  k25,    k26,      k27, k28, k29, k30, \
	                   k31,  k32,    k33, k34



// 3x5_2 to 36-key conversion
#define C_36(k) SPLIT_34_TO_36(k)
#define SPLIT_34_TO_36( \
	     k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, \
	     k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, \
	     k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, \
	                    k31, k32,    k33, k34 \
) \
	     k01, k02, k03, k04, k05,    k06, k07, k08, k09, k10, \
	     k11, k12, k13, k14, k15,    k16, k17, k18, k19, k20, \
	     k21, k22, k23, k24, k25,    k26, k27, k28, k29, k30, \
	            KC_DEL, k31, k32,    k33, k34, KC_ENT \


// Layout aliases
#define LAYOUT_fifi(...) LAYOUT_split_3x5_3(__VA_ARGS__)
//#define LAYOUT_ortho_w(...) LAYOUT_ortho_4x12(__VA_ARGS__)
//#define LAYOUT_36key_w(...) LAYOUT(__VA_ARGS__)
//#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)