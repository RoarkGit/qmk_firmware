// Copyright 2022 Yoga Benggolo
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum custom_layer {
	_QWERTZ,
	_RAISE,
};

#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTZ] = LAYOUT(
		KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,              KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_HOME,
		KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,              KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_END ,
		XXXXXXX, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,              KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_RBRC,
		RAISE  , KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,              KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_NUHS,
		KC_LCTL, KC_NUBS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,              KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_MPLY,
		                           KC_LEFT, KC_RGHT,                                                  KC_UP  , KC_DOWN,
		                                             KC_SPC , KC_LSFT,              KC_RALT, KC_ENT ,
		                                             KC_LGUI, KC_LALT,              KC_BSPC, KC_DEL ,
		                                             KC_PGDN, KC_PGUP,              KC_TAB , KC_INS
		),

	[_RAISE] = LAYOUT(
		QK_BOOT, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______,              _______, _______, _______, _______, _______, _______, _______,
		                           KC_MPRV, KC_MNXT,                                                  KC_VOLU, KC_VOLD,
	                                                 _______, _______,              _______, _______,
													 _______, _______,              _______, _______,
													 _______, _______,              _______, _______
		)
};
