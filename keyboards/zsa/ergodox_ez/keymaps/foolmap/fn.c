void clear() {
  clear_oneshot_mods();
  clear_oneshot_locked_mods();
  clear_keyboard();
  reset_oneshot_layer();
  layer_clear();
  layer_on(BASE);
  rgb_matrix_set_color_all(0, 0, 0);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case CLEAR:
        clear();
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
    rgb_matrix_set_color_all(128, 0, 0);
  } else if (locked_mods & MOD_MASK_SHIFT) {
    rgb_matrix_set_color_all(255, 0, 0);
  } else {
    rgb_matrix_set_color_all(0, 0, 0);
  }

  if (mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color_all(0, 128, 0);
  } else if (locked_mods & MOD_MASK_CTRL) {
    rgb_matrix_set_color_all(0, 255, 0);
  } else {
    rgb_matrix_set_color_all(0, 0, 0);
  }

  if (mods & MOD_MASK_ALT) {
    rgb_matrix_set_color_all(0, 0, 128);
  } else if (locked_mods & MOD_MASK_ALT) {
    rgb_matrix_set_color_all(0, 0, 255);
  } else {
    rgb_matrix_set_color_all(0, 0, 0);
  }

  if (mods & MOD_MASK_GUI) {
    rgb_matrix_set_color_all(0, 100, 200);
  } else if (locked_mods & MOD_MASK_GUI) {
    rgb_matrix_set_color_all(100, 200, 255);
  } else {
    rgb_matrix_set_color_all(0, 0, 0);
  }

  return true;
}
