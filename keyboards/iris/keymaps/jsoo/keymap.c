#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define CTRL_ESC MT(MOD_LCTL, KC_ESC)
#define LOWER_ENT LT(_LOWER, KC_ENT)
#define RAISE_SPC LT(_RAISE, KC_SPC)
#define ADJUST_QUOT LT(_ADJUST, KC_QUOT)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

enum tapdances {
  TD_LBRC = 0,
  TD_RBRC,
  TD_EQL,
  TD_UNDS,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTRL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, ADJUST_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,          _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   KC_LALT,  KC_LGUI, LOWER_ENT,                RAISE_SPC, KC_RGUI, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                             KC_RBRC,   KC_P4,   KC_P5,   KC_P6, KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR,  _______,          _______, KC_RCBR, KC_P1,   KC_LABK, KC_RABK, KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TILDE, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR,TD(TD_LBRC),TD(TD_RBRC), _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_LEFT,  KC_DOWN,  KC_UP, KC_RIGHT, _______, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, TD(TD_UNDS), _______,     _______, TD(TD_EQL), KC_END, KC_LABK, KC_RABK, KC_SLASH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______,  _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                           _______,  _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______,  _______, _______, _______, _______, _______, _______,          _______, _______, _______,  _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void td_braces_open_register(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
    register_code(KC_9);
    break;
  case 2:
    register_code(KC_LBRC);
    break;
  default:
    register_code(KC_LSFT);
    register_code(KC_LBRC);
  }
}

void td_braces_open_unregister(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    unregister_code(KC_9);
    unregister_code(KC_LSFT);
    break;
  case 2:
    unregister_code(KC_LBRC);
    break;
  default:
    unregister_code(KC_LBRC);
    unregister_code(KC_LSFT);
  }
}

void td_braces_close_register(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_LSFT);
    register_code(KC_0);
    break;
  case 2:
    register_code(KC_RBRC);
    break;
  default:
    register_code(KC_LSFT);
    register_code(KC_RBRC);
  }
}

void td_braces_close_unregister(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    unregister_code(KC_0);
    unregister_code(KC_LSFT);
    break;
  case 2:
    unregister_code(KC_RBRC);
    break;
  default:
    unregister_code(KC_RBRC);
    unregister_code(KC_LSFT);
  }
}

void td_eq_register(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_EQL);
    break;
  default:
    register_code(KC_LSFT);
    register_code(KC_EQL);
  }
}

void td_eq_unregister(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    unregister_code(KC_EQL);
    break;
  default:
    unregister_code(KC_EQL);
    unregister_code(KC_LSFT);
  }
}

void td_unds_register(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    register_code(KC_MINS);
    break;
  default:
    register_code(KC_LSFT);
    register_code(KC_MINS);
  }
}

void td_unds_unregister(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    unregister_code(KC_MINS);
    break;
  default:
    unregister_code(KC_MINS);
    unregister_code(KC_LSFT);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_braces_open_register, td_braces_open_unregister),
    [TD_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_braces_close_register, td_braces_close_unregister),
    [TD_EQL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_eq_register, td_eq_unregister),
    [TD_UNDS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_unds_register, td_unds_unregister)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
