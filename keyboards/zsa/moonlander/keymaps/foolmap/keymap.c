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
#define LEFT_CTRL_INDEX 33
#define RIGHT_CTRL_INDEX 69
#define LEFT_ALT_INDEX 34
#define RIGHT_ALT_INDEX 70
#define LEFT_GUI_INDEX 4
#define RIGHT_GUI_INDEX 40

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
 * | @MOVE |   A   | HOMEO | HOMEE | HOMEU | INDXI | ^LSFT | ^RSFT | INDXD | HOMEH | HOMET | HOMEN |   S   | @MOVE |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | CLEAR |   ;   |   Q   |   J   |   K   | DIAGX |               | DIAGB |   M   |   W   |   V   |   Z   | CLEAR |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * | ^LGUI | HOME  | PGUP  | PGDN  |  END  | @SYMB |               | @SYMB | LEFT  | DOWN  |  UP   | RIGHT | ^RGUI |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |  SPC  | ^LCTL | ^LALT |               | ^RALT | ^RCTL |  SPC  |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[BASE] = LAYOUT_moonlander(
        KC_MUTE,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,      KC_ESC,        KC_BSPC,       KC_6,    KC_7,   KC_8,     KC_9,          KC_0, KC_VOLU,
        KC_MPLY,       KC_QUOT,       KC_COMM,       KC_DOT,        KC_P,          KC_Y,      KC_TAB,        KC_ENT,        KC_F,    KC_G,   KC_C,     KC_R,          KC_L, KC_VOLD,
        OSL(MOVE),     KC_A,          HOME_O,        HOME_E,        HOME_U,        INDX_I,    OSM(MOD_LSFT), OSM(MOD_RSFT), INDX_D,  HOME_H, HOME_T,   HOME_N,        KC_S, OSL(MOVE),
        CLEAR,         KC_SCLN,       KC_Q,          KC_J,          KC_K,          DIAG_X,    DIAG_B,        KC_M,          KC_W,    KC_V,   KC_Z,     CLEAR,
        OSM(MOD_LGUI), KC_HOME,       KC_PGUP,       KC_PGDN,       KC_END,        OSL(SYMB), OSL(SYMB),     KC_LEFT,       KC_DOWN, KC_UP,  KC_RIGHT, OSM(MOD_RGUI),
        KC_SPC,        OSM(MOD_LCTL), OSM(MOD_LALT), OSM(MOD_RALT), OSM(MOD_RCTL), KC_SPC
),

/* Layer: SYMB
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |  F1   |  F2   |  F3   |  F4   |  F5   |       |       |  F6   |  F7   |  F8   |  F9   |  F10  |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | MPRV  |   !   |   @   |   #   |   $   |   %   |       |       |   ^   |   &   |   *   |  F11  |  F12  | WBAK  |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * | MNXT  |   {   |   }   |   (   |   )   |   =   |       |       |   /   |   -   |   _   |   [   |   ]   | WFWD  |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |   ~   |   |   |   `   |               |   \   |   +   |  DEL  |  INS  |   \   |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[SYMB] = LAYOUT_moonlander(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
        KC_MPRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_F11,  KC_F12,  KC_WBAK,
        KC_MNXT, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EQL,  _______, _______, KC_SLSH, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, KC_WFWD,
        _______, _______, _______, KC_TILD, KC_PIPE, KC_GRV,  KC_BSLS, KC_PLUS, KC_DEL,  KC_INS,  KC_BSLS, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
),

/* Layer: MOVE
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |  WHD  |  MSU  |  WHU  | PGUP  |       |       | BTN2  | ACL0  |  UP   | ACL1  | ACL2  |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |  MSL  |  MSD  |  MSR  | PGDN  |       |       | BTN1  | LEFT  | DOWN  | RIGHT |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       | RGB+  | RGB-  | HOME  |  END  | BOOT  |               | BOOT  |  WHL  |  WHR  |       |RGBTOG |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[MOVE] = LAYOUT_moonlander(
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, KC_WH_D,  KC_MS_U, KC_WH_U, KC_PGUP, _______, _______, KC_BTN2, KC_ACL0, KC_UP,   KC_ACL1,  KC_ACL2, _______,
        _______, _______, KC_MS_L,  KC_MS_D, KC_MS_R, KC_PGDN, _______, _______, KC_BTN1, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, RGB_MOD, RGB_RMOD, KC_HOME, KC_END,  QK_BOOT, QK_BOOT, KC_WH_L, KC_WH_R, _______, RGB_TOG, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,  _______, _______, _______
),

/* Layer: INDX
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |       |       |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       | BTN2  |  MSU  | BTN1  |  ESC  |       |       | BSPC  | HOME  |  UP   |  END  |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |  MSL  |  MSD  |  MSR  |  TAB  |       |       |  ENT  | LEFT  | DOWN  | RIGHT |       |       |
 * +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |  WHD  |  WHU  |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 * |       |       |       |       |       |       |               |       |       |       |       |       |       |
 * +-------+-------+-------+-------+-------+-------+               +-------+-------+-------+-------+-------+-------+
 *                         |       |       |       |               |       |       |       |
 *                         +-------+-------+-------+               +-------+-------+-------+
 */

[INDX] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_ESC,  _______, _______, KC_BSPC, KC_HOME, KC_UP,   KC_END,   _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_TAB,  _______, _______, KC_ENT,  KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_WH_U, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
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
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 128, 0, 0);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 128, 0, 0);
  } else if (locked_mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 255, 0, 0);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 255, 0, 0);
  } else {
    reset_color(LEFT_SHIFT_INDEX);
    reset_color(RIGHT_SHIFT_INDEX);
  }

  if (mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color(LEFT_CTRL_INDEX, 0, 128, 0);
    rgb_matrix_set_color(RIGHT_CTRL_INDEX, 0, 128, 0);
  } else if (locked_mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color(LEFT_CTRL_INDEX, 0, 255, 0);
    rgb_matrix_set_color(RIGHT_CTRL_INDEX, 0, 255, 0);
  } else {
    reset_color(LEFT_CTRL_INDEX);
    reset_color(RIGHT_CTRL_INDEX);
  }

  if (mods & MOD_MASK_ALT) {
    rgb_matrix_set_color(LEFT_ALT_INDEX, 0, 0, 128);
    rgb_matrix_set_color(RIGHT_ALT_INDEX, 0, 0, 128);
  } else if (locked_mods & MOD_MASK_ALT) {
    rgb_matrix_set_color(LEFT_ALT_INDEX, 0, 0, 255);
    rgb_matrix_set_color(RIGHT_ALT_INDEX, 0, 0, 255);
  } else {
    reset_color(LEFT_ALT_INDEX);
    reset_color(RIGHT_ALT_INDEX);
  }

  if (mods & MOD_MASK_GUI) {
    rgb_matrix_set_color(LEFT_GUI_INDEX, 0, 100, 200);
    rgb_matrix_set_color(RIGHT_GUI_INDEX, 0, 100, 200);
  } else if (locked_mods & MOD_MASK_GUI) {
    rgb_matrix_set_color(LEFT_GUI_INDEX, 100, 200, 255);
    rgb_matrix_set_color(RIGHT_GUI_INDEX, 100, 200, 255);
  } else {
    reset_color(LEFT_GUI_INDEX);
    reset_color(RIGHT_GUI_INDEX);
  }

  return true;
}
