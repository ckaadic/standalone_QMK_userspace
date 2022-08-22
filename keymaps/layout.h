


// Home row mod-tap macros
#define HM_A	LSFT_T(KC_A)
#define HM_S	LALT_T(KC_S)
#define HM_D	LCTL_T(KC_D)
#define HM_F	LGUI_T(KC_F)
#define HM_J	LGUI_T(KC_J)
#define HM_K	LCTL_T(KC_K)
#define HM_L	LALT_T(KC_L)
#define HM_QUOT	LSFT_T(KC_QUOT)
#define HRML(k1,k2,k3,k4) LGUI_T(k1),LALT_T(k2),LCTL_T(k3),LSFT_T(k4)
#define HRMR(k1,k2,k3,k4) LSFT_T(k1),LCTL_T(k2),LALT_T(k3),LGUI_T(k4)

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

// Navigation shortcuts
#define RSA_UP RSA(KC_UP)
#define RSA_DN RSA(KC_DOWN)

// Layers
#define BSE 0
#define CMK 1
#define NUM 2
#define SYM 3
#define FNC 4


// Default 3x6_3 split layout
#define _BASE \
	KC_NO, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO, \
	KC_NO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_NO, \
	KC_NO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, \
	                    KC_DEL, LT(SYM,KC_BSPC), OSM_SFT,     KC_SPC, LT(NUM,KC_TAB), KC_ENT
/* ,-----------------------------------------.                ,-----------------------------------------.
   |      |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |  A   |  S   |  D   |  F   |  G   |                |  H   |  J   |  K   |  L   | ' "  |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  |      |
   `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
                               | DEL  |_SYMB | OSM_ |  |RSFT_T|_NUMB | ENT  |
                               |      | BSPC | SFT  |  | SPC  | TAB  |      |
                               `--------------------'  `--------------------'
 */
#define _COLE \
	KC_NO, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_NO, \
	KC_NO, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_NO, \
	KC_NO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO, \
	                    KC_DEL, LT(SYM,KC_BSPC), OSM_SFT,     KC_SPC, LT(NUM,KC_TAB), KC_ENT
/* ,-----------------------------------------.                ,-----------------------------------------.
   |      |  Q   |  W   |  F   |  P   |  B   |                |  J   |  L   |  U   |  Y   | ' "  |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |  A   |  R   |  S   |  T   |  G   |                |  M   |  N   |  E   |  I   |  O   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |  Z   |  X   |  C   |  D   |  V   |                |  K   |  H   | , <  | . >  | / ?  |      |
   `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
                               | DEL |_SYMB | OSM_ |  |RSFT_T|_NUMB | ENT  |
                               |      | BSPC | SFT  |  | SPC  | TAB  |      |
                               `--------------------'  `--------------------'
 */
#define _NUMB \
	KC_NO, KC_SCLN, KC_HASH, KC_AT,   KC_UNDS, KC_EXLM,     KC_ASTR, KC_MINS, KC_EQL,  KC_PLUS, KC_GRV,  KC_NO, \
	KC_NO, KC_COLN, KC_BSLS, KC_LCBR, KC_LPRN, KC_LBRC,     KC_3,    KC_2,    KC_1,    KC_0,    KC_4,    KC_NO, \
	KC_NO, KC_CIRC, KC_AMPR, KC_PERC, KC_DLR,  KC_DOT,      KC_7,    KC_6,    KC_5,    KC_9,    KC_8,    KC_NO, \
	                           KC_NO, MO(FNC), KC_TRNS,     KC_NO, KC_NO, KC_NO
/* ,-----------------------------------------.                ,-----------------------------------------.
   |      | INS  |  1   |  2   |  3   | VOLU |                | HOME | PGDN | PGUP | END  |  :   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      | DEL  |  4   |  5   |  6   | VOLD |                | LEFT | DOWN |  UP  | RGHT |  ;   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      | CAPS |  7   |  8   |  9   |  0   |                |      |RSA_DN|RSA_UP|      |      |      |
   `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
                               |      |_FUNC | GESC |  |      |      |      |
                               `--------------------'  `--------------------'
 */
#define _SYMB \
	KC_NO, KC_ESC,  KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO, KC_PGUP, KC_UP,   RALT(KC_S), KC_NO, KC_NO, \
	KC_NO, OSM_GUI, OSM_ALT,   OSM_CTL, OSM_SFT, C(KC_S),   KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,     KC_NO, \
	KC_NO, KC_ENT,  CAPS_WORD, C(KC_C), KC_DEL,  C(KC_V),   KC_NO, KC_PGDN, KC_NO, KC_NO, KC_NO,    KC_NO, \
	                             KC_NO, KC_NO, KC_NO,   KC_TAB,  KC_ENT,  KC_NO
/* ,-----------------------------------------.                ,-----------------------------------------.
   |      |      |  [   |  {   |  }   |      |                |  ^   |  (   |  )   |  ]   |  ~   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |  !   |  @   |  #   |  $   |  %   |                |  *   |  -   |  =   |  \   |  `   |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |      |      |      |      |      |                |  &   |  _   |  +   |  |   |      |      |
   `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
                               |      |      |      |  |      |_FUNC |      |
                               `--------------------'  `--------------------'
 */
#define _FUNC \
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_NO, KC_NO, \
	KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  RGB_TOG,    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_NO, KC_NO, \
	KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, KC_NO,    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_NO, KC_NO, \
	                           KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO
/* ,-----------------------------------------.                ,-----------------------------------------.
   |      |BOOT  |  F1  |  F2  |  F3  | F10  |                |      | WH_U | WH_D |      |_COLE |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |      |  F4  |  F5  |  F6  | F11  |                | MS_L | MS_D | MS_U | MS_R |      |      |
   |------+------+------+------+------+------|                |------+------+------+------+------+------|
   |      |SLEEP |  F7  |  F8  |  F9  | F12  |                |      | BTN2 | BTN1 |      |SSAVE |      |
   `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
                               |      |      |      |  |      |      |      |
                               `--------------------'  `--------------------'
 */

// 3x6_3 home row mod and tap hold wrapper
#define HRM(k) HRM_TAPHOLD(k)
#define HRM_TAPHOLD( \
	      k01, k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, k12, \
	      k13, k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, k24, \
	      k25, k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, k36, \
	                     k37, k38, k39,    k40, k41, k42 \
) \
	k01,      k02, k03, k04, k05,  k06,    k07,      k08, k09, k10, k11,  k12, \
	k13, HRML(k14, k15, k16, k17), k18,    k19, HRMR(k20, k21, k22, k23), k24, \
	k25,      k26, k27, k28, k29,  k30,    k31,      k32, k33, k34, k35,  k36, \
	                    k37, k38,  k39,    k40, k41, k42



// Layout aliases
#define LAYOUT_corne_w(...) LAYOUT_split_3x6_3(__VA_ARGS__)
#define LAYOUT_36key_w(...) LAYOUT_split_3x5_3(__VA_ARGS__)
#define LAYOUT_34key_w(...) LAYOUT_split_3x5_2(__VA_ARGS__)
#define LAYOUT_reviung34_w(...) LAYOUT_reviung34(__VA_ARGS__)



// 3x6_3 to 36-key conversion
#define C_36(k) SPLIT_42_TO_36(k)
#define SPLIT_42_TO_36( \
	k01, k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, k12, \
	k13, k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, k24, \
	k25, k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, k36, \
	               k37, k38, k39,    k40, k41, k42 \
) \
	     k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, \
	     k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, \
	     k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, \
	               k37, k38, k39,    k40, k41, k42

// 3x6_3 to 34-key conversion
#define C_34(k) SPLIT_42_TO_34(k)
#define SPLIT_42_TO_34( \
	k01, k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, k12, \
	k13, k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, k24, \
	k25, k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, k36, \
	               k37, k38, k39,    k40, k41, k42 \
) \
	     k02, k03, k04, k05, k06,    k07, k08, k09, k10, k11, \
	     k14, k15, k16, k17, k18,    k19, k20, k21, k22, k23, \
	     k26, k27, k28, k29, k30,    k31, k32, k33, k34, k35, \
	                    k38, k39,    k40, k41

