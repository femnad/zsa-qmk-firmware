#define LEFT_SHIFT_INDEX 31
#define RIGHT_SHIFT_INDEX 67
#define LEFT_CTRL_INDEX 33
#define RIGHT_CTRL_INDEX 69
#define LEFT_ALT_INDEX 34
#define RIGHT_ALT_INDEX 70
#define LEFT_GUI_INDEX 4
#define RIGHT_GUI_INDEX 40

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
    rgb_matrix_set_color(LEFT_SHIFT_INDEX, 0, 0, 0);
    rgb_matrix_set_color(RIGHT_SHIFT_INDEX, 0, 0, 0);
  }

  if (mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color(LEFT_CTRL_INDEX, 0, 128, 0);
    rgb_matrix_set_color(RIGHT_CTRL_INDEX, 0, 128, 0);
  } else if (locked_mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color(LEFT_CTRL_INDEX, 0, 255, 0);
    rgb_matrix_set_color(RIGHT_CTRL_INDEX, 0, 255, 0);
  } else {
    rgb_matrix_set_color(LEFT_CTRL_INDEX, 0, 0, 0);
    rgb_matrix_set_color(RIGHT_CTRL_INDEX, 0, 0, 0);
  }

  if (mods & MOD_MASK_ALT) {
    rgb_matrix_set_color(LEFT_ALT_INDEX, 0, 0, 128);
    rgb_matrix_set_color(RIGHT_ALT_INDEX, 0, 0, 128);
  } else if (locked_mods & MOD_MASK_ALT) {
    rgb_matrix_set_color(LEFT_ALT_INDEX, 0, 0, 255);
    rgb_matrix_set_color(RIGHT_ALT_INDEX, 0, 0, 255);
  } else {
    rgb_matrix_set_color(LEFT_ALT_INDEX, 0, 0, 0);
    rgb_matrix_set_color(RIGHT_ALT_INDEX, 0, 0, 0);
  }

  if (mods & MOD_MASK_GUI) {
    rgb_matrix_set_color(LEFT_GUI_INDEX, 0, 100, 200);
    rgb_matrix_set_color(RIGHT_GUI_INDEX, 0, 100, 200);
  } else if (locked_mods & MOD_MASK_GUI) {
    rgb_matrix_set_color(LEFT_GUI_INDEX, 100, 200, 255);
    rgb_matrix_set_color(RIGHT_GUI_INDEX, 100, 200, 255);
  } else {
    rgb_matrix_set_color(LEFT_GUI_INDEX, 0, 0, 0);
    rgb_matrix_set_color(RIGHT_GUI_INDEX, 0, 0, 0);
  }

  return true;
}
