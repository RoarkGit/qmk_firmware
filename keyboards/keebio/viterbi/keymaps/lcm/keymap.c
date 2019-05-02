#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

// Custom defines
#define ESCTL CTL_T(KC_ESC)
#define SHENT SFT_T(KC_ENT)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |      |   7  |   8  |   9  |   0  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | Home |      | PgUp |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |EsCtl |   A  |   S  |   D  |   F  |   G  | End  |      | PgDn |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | PrScn|      | Caps |   N  |   M  |   ,  |   .  |   /  | ShEnt|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |Adjust|	Ctrl | Super| Alt  |Lower |    Space    |      |    Space    |Raise | Left | Down | Right|  Up  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_GRV,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL,  KC_DEL ,
    KC_TAB,  KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_HOME,     KC_PGUP, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    ESCTL,   KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_END ,     KC_PGDN, KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_PSCR,     KC_CAPS, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SHENT  ,
    ADJUST , KC_LCTL, KC_LGUI, KC_LALT, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),
  
/* COLEMAK
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |   6  |      |   7  |   8  |   9  |   0  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  | Home |      | PgUp |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |EsCtl |   A  |   R  |   S  |   T  |   D  | End  |      | PgDn |   H  |   N  |   E  |   I  |   O  |   "  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | PrScn|      | Caps |   K  |   M  |   ,  |   .  |   /  | ShEnt|
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |Adjust|	Ctrl | Super| Alt  |Lower |    Space    |      |    Space    |Raise | Left | Down | Right|  Up  |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_COLEMAK] = LAYOUT_ortho_5x14(
    KC_GRV,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,     KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL,  KC_DEL ,
    KC_TAB,  KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_HOME,     KC_PGUP, KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
    ESCTL,   KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_END ,     KC_PGDN, KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_PSCR,     KC_CAPS, KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, SHENT  ,
    ADJUST , KC_LCTL, KC_LGUI, KC_LALT, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |      |      |      |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | VolUp| VolDn|      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______,     _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______
  ),

/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |      |      |      |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   -  |   =  |   [  |   ]  |   \  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),


  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,  _______,
    _______, RESET  , _______, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, AG_NORM,     AG_SWAP, _______, QWERTY , COLEMAK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
	case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
