/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "lib/keyball/keyball.h"

#ifdef COMBO_ENABLE
enum combos {
  COMBO_LSFT_BSPC,
  COMBO_RSFT_BSPC,
  COMBO_LSFT_LANG2,
  COMBO_RSFT_LANG2,
};

const uint16_t PROGMEM combo_lsft_bspc[] = {KC_LSFT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_rsft_bspc[] = {KC_RSFT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combo_lsft_lang2[] = {KC_LSFT, KC_LNG2, COMBO_END};
const uint16_t PROGMEM combo_rsft_lang2[] = {KC_RSFT, KC_LNG2, COMBO_END};

combo_t key_combos[] = {
[COMBO_LSFT_BSPC] = COMBO(combo_lsft_bspc, KC_DEL),
[COMBO_RSFT_BSPC] = COMBO(combo_rsft_bspc, KC_DEL),
[COMBO_LSFT_LANG2] = COMBO(combo_lsft_lang2, KC_LNG1),
[COMBO_RSFT_LANG2] = COMBO(combo_rsft_lang2, KC_LNG1),
};
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_right_ball(
    KC_ESC	, KC_Q	, KC_W	, KC_E	, KC_R	, KC_T	,	KC_Y	, KC_U	, KC_I	, KC_O	, KC_P	, KC_DEL	,
    KC_TAB	, KC_A	, KC_S	, KC_D	, KC_F	, KC_G	,	KC_H	, KC_J	, KC_K	, KC_L	, KC_SCLN	, S(KC_7)	,
    KC_LSFT	, KC_Z	, KC_X	, KC_C	, KC_V	, KC_B	,	KC_N	, KC_M	, KC_COMM	, KC_DOT	, KC_SLSH	, KC_INT1	,
    KC_LALT	, KC_LGUI	, KC_LSFT	, LT(1,KC_SPC), LT(3,KC_LNG1),		KC_BSPC, LT(2,KC_ENT), KC_RALT
  ),

  [1] = LAYOUT_right_ball(
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______ , _______	, _______	, KC_UP	, KC_ENT	, KC_DEL	,	KC_PGUP	, MS_BTN1	, KC_UP	, MS_BTN2	, MS_BTN3	, KC_F12	,
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	,		_______	, _______	, _______
  ),

  [2] = LAYOUT_right_ball(
    _______	,S(KC_QUOT), KC_7	, KC_8	, KC_9	, S(KC_8)	,	S(KC_9)	, S(KC_1)	, S(KC_6)	, KC_LBRC	, S(KC_4)	, _______	,
    _______	,S(KC_SCLN), KC_4	, KC_5	, KC_6	, KC_RBRC	,	KC_NUHS	, KC_MINS	, S(KC_EQL)	, S(KC_3)	, KC_QUOT	, S(KC_2)	,
    _______	,S(KC_MINS), KC_1	, KC_2	, KC_3	, S(KC_RBRC),	S(KC_NUHS),S(KC_INT1), KC_EQL	, S(KC_LBRC),S(KC_SLSH)	,S(KC_INT3)	,
    KC_0	, KC_DOT	, _______	, _______	, _______	,		KC_DEL	, _______	, _______
  ),

  [3] = LAYOUT_right_ball(
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	,		_______	, _______	, _______
  ),

  [4] = LAYOUT_right_ball(
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	, _______	,	_______	, _______	, _______	, _______	, _______	, _______	,
    _______	, _______	, _______	, _______	, _______	,		_______	, _______	, _______
  ),
};
// clang-format on

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
