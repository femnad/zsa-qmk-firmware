#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0
#define SYMB 1
#define MOVE 2
#define INDX 3

#define DIAG_B MT(MOD_RSFT, KC_B)
#define DIAG_X MT(MOD_LSFT, KC_X)
#define HOME_E MT(MOD_LALT, KC_E)
#define HOME_H MT(MOD_RCTL, KC_H)
#define HOME_N MT(MOD_RGUI, KC_N)
#define HOME_O MT(MOD_LGUI, KC_O)
#define HOME_T MT(MOD_RALT, KC_T)
#define HOME_U MT(MOD_LCTL, KC_U)
#define INDX_I LT(INDX, KC_I)
#define INDX_D LT(INDX, KC_D)
#define LEFT_SHIFT_INDEX 31
#define RIGHT_SHIFT_INDEX 67
#define INDX_OSL_LEFT_INDEX 24
#define INDX_OSL_RIGHT_INDEX 60
#define SYMB_OSL_LEFT_INDEX 33
#define SYMB_OSL_RIGHT_INDEX 69
#define MOVE_OSL_LEFT_INDEX 34
#define MOVE_OSL_RIGHT_INDEX 70

enum custom_keycodes {
  CLEAR = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer: BASE
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | MUTE  |   1   |   2   |   3   |   4   |   5   |  ESC  | BSPC  |   6   |   7   |   8   |   9   |   0   | VOLU  |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | MPLY  |   '   |   ,   |   .   |   P   |   Y   |  TAB  |  ENT  |   F   |   G   |   C   |   R   |   L   | VOLD  |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | CLEAR |   A   | HOMEO | HOMEE | HOMEU | INDXI | ^LSFT | ^RSFT | INDXD | HOMEH | HOMET | HOMEN |   S   | CLEAR |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | MPRV  |   ;   |   Q   |   J   |   K   | DIAGX |               | DIAGB |   M   |   W   |   V   |   Z   | MNXT  |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * | HOME  | PGUP  | PGDN  |  END  | @INDX | LGUI  |               | LGUI  | @INDX | LEFT  | DOWN  |  UP   | RIGHT |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |  SPC  | @SYMB | @MOVE |               | @MOVE | @SYMB |  SPC  |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[BASE] = LAYOUT_moonlander(
        KC_MUTE, KC_1,      KC_2,      KC_3,      KC_4,      KC_5,    KC_ESC,        KC_BSPC,       KC_6,    KC_7,    KC_8,   KC_9,     KC_0, KC_VOLU,
        KC_MPLY, KC_QUOT,   KC_COMM,   KC_DOT,    KC_P,      KC_Y,    KC_TAB,        KC_ENT,        KC_F,    KC_G,    KC_C,   KC_R,     KC_L, KC_VOLD,
        CLEAR,   KC_A,      HOME_O,    HOME_E,    HOME_U,    INDX_I,  OSM(MOD_LSFT), OSM(MOD_RSFT), INDX_D,  HOME_H,  HOME_T, HOME_N,   KC_S, CLEAR,
        KC_MPRV, KC_SCLN,   KC_Q,      KC_J,      KC_K,      DIAG_X,  DIAG_B,        KC_M,          KC_W,    KC_V,    KC_Z,   KC_MNXT,
        KC_HOME, KC_PGUP,   KC_PGDN,   KC_END,    OSL(INDX), KC_LGUI, KC_LGUI,       OSL(INDX),     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,
        KC_SPC,  OSL(SYMB), OSL(MOVE), OSL(MOVE), OSL(SYMB), KC_SPC
),

/* Layer: SYMB
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |       |       |  F6   |  F7   |  F8   |  F9   |  F10  |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |   !   |   @   |   #   |   $   |   %   |       |       |   ^   |   &   |   *   |  F11  |  F12  |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |   {   |   }   |   (   |   )   |   =   |       |       |   /   |   -   |   _   |   [   |   ]   |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |   ~   |   |   |   `   |               |   \   |   +   |  DEL  |  INS  |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[SYMB] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  _______,
        _______, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL,  _______, _______, KC_SLSH, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, _______,
        _______, _______, _______, KC_TILD, KC_PIPE, KC_GRV,  KC_BSLS, KC_PLUS, KC_DEL,  KC_INS,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
),

/* Layer: MOVE
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |  MSU  |       |  WHU  |       |       | BTN5  | ACL0  | ACL1  | ACL2  |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |  MSL  |  MSD  |  MSR  |  WHD  |       |       | BTN4  | BTN1  | BTN3  | BTN2  |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       | BOOT  | RGB+  | RGB-  |       |CWTOGG |               |CWTOGG |C-S-TAB| C-TAB |RGBTOG | BOOT  |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[MOVE] = LAYOUT_moonlander(
        _______, _______, _______, _______,  _______, _______, _______, _______,            _______,      _______, _______, _______, _______, _______,
        _______, _______, _______, MS_UP,    _______, MS_WHLU, _______, _______,            KC_BTN5,      KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
        _______, _______, MS_LEFT, MS_DOWN,  MS_RGHT, MS_WHLD, _______, _______,            KC_BTN4,      MS_BTN1, KC_BTN3, MS_BTN2, _______, _______,
        _______, QK_BOOT, RGB_MOD, RGB_RMOD, _______, CW_TOGG, CW_TOGG, RCTL(RSFT(KC_TAB)), RCTL(KC_TAB), RGB_TOG, QK_BOOT, _______,
        _______, _______, _______, _______,  _______, _______, _______, _______,            _______,      _______, _______, _______,
        _______, _______, _______, _______,  _______, _______
),

/* Layer: INDX
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       | PGUP  |       |  ESC  |       |       | BSPC  |       |  UP   |       |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       | HOME  | PGDN  |  END  |  TAB  |       |       |  ENT  | LEFT  | DOWN  | RIGHT |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |CWTOGG |               |CWTOGG |C-S-TAB| C-TAB |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[INDX] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______, _______,            _______,      _______, _______, _______,  _______, _______,
        _______, _______, _______, KC_PGUP, _______, KC_ESC,  _______, _______,            KC_BSPC,      _______, KC_UP,   _______,  _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END,  KC_TAB,  _______, _______,            KC_ENT,       KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, CW_TOGG, CW_TOGG, RCTL(RSFT(KC_TAB)), RCTL(KC_TAB), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,            _______,      _______, _______, _______,
        _______, _______, _______, _______, _______, _______
),

};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_moonlander(
    'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',           '*', '*', '*'
);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DIAG_B:
        case DIAG_X:
        case HOME_E:
        case HOME_H:
        case HOME_N:
        case HOME_O:
        case HOME_T:
        case HOME_U:
        case INDX_D:
        case INDX_I:
            return 350;
        default:
            return TAPPING_TERM;
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
        caps_word_off();
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        clear_keyboard();
        reset_oneshot_layer();
        layer_clear();
        layer_on(BASE);
        rgb_matrix_set_color_all(0, 0, 0);
        return false;
    }
 }
  return true;
}

void maybe_reset_rgb_matrix(uint8_t mods) {
  if (mods == 0) {
    rgb_matrix_set_color_all(0, 0, 0);
  }
}

void oneshot_mods_changed_user(uint8_t mods) {
  maybe_reset_rgb_matrix(mods);
}

void oneshot_locked_mods_changed_user(uint8_t mods) {
  maybe_reset_rgb_matrix(mods);
}

void reset_color(int index) {
    rgb_matrix_set_color(index, 0, 0, 0);
}

bool rgb_matrix_indicators_user(void) {
  uint8_t mods = get_oneshot_mods();
  uint8_t locked_mods = get_oneshot_locked_mods();

  if (mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 128, 0, 128);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 128, 0, 128);
  } else if (locked_mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 255, 0, 255);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 255, 0, 255);
  } else {
    reset_color(LEFT_SHIFT_INDEX);
    reset_color(RIGHT_SHIFT_INDEX);
  }

  uint8_t osl_state = get_oneshot_layer_state();
  uint8_t osl_left_index = 0, osl_right_index = 0;
  uint8_t osl_r = 0, osl_g = 0, osl_b = 0;
  switch (get_oneshot_layer()) {
    case INDX:
      osl_left_index = INDX_OSL_LEFT_INDEX;
      osl_right_index = INDX_OSL_RIGHT_INDEX;
      osl_r = 255;
      break;
    case SYMB:
      osl_left_index = SYMB_OSL_LEFT_INDEX;
      osl_right_index = SYMB_OSL_RIGHT_INDEX;
      osl_b = 255;
      break;
    case MOVE:
      osl_left_index = MOVE_OSL_LEFT_INDEX;
      osl_right_index = MOVE_OSL_RIGHT_INDEX;
      osl_g = 255;
      break;
  }

  if (osl_state & ONESHOT_TOGGLED) {
    rgb_matrix_set_color(osl_left_index, osl_r, osl_g, osl_b);
    rgb_matrix_set_color(osl_right_index, osl_r, osl_g, osl_b);
  } else if (osl_state) {
    rgb_matrix_set_color(osl_left_index, osl_r / 2, osl_g / 2, osl_b / 2);
    rgb_matrix_set_color(osl_right_index, osl_r / 2, osl_g / 2, osl_b / 2);
  } else {
    reset_color(INDX_OSL_LEFT_INDEX);
    reset_color(INDX_OSL_RIGHT_INDEX);
    reset_color(SYMB_OSL_LEFT_INDEX);
    reset_color(SYMB_OSL_RIGHT_INDEX);
    reset_color(MOVE_OSL_LEFT_INDEX);
    reset_color(MOVE_OSL_RIGHT_INDEX);
  }

  return true;
}
