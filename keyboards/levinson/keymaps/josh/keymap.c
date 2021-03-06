#include QMK_KEYBOARD_H
// Helpful defines
#define _______ KC_TRNS
#define xxxxxxx KC_NO

// Shorten Keynames
#define SHGUI SCMD(xxxxxxx)

// Leader Key Funsies!
#define LEADER_TIMEOUT 350

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
#include "emotes.h"

        SEQ_TWO_KEYS(KC_L, KC_S) {
            SEND_STRING(SS_LGUI(SS_TAP(X_HOME)));
        }

        SEQ_TWO_KEYS(KC_C, KC_W) {
            SEND_STRING(SS_LGUI(SS_TAP(X_END)));
        }
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LGUI |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | LALT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |MO(4) | SGUI |MO(2) | MO(3)|LSHFT |Space | MO(1)| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
  [0] = LAYOUT_ortho_4x12(
      KC_GESC, KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
      KC_TAB,  KC_A,    KC_O,    KC_E,   KC_U,     KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT,
      KC_LGUI, KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_LALT,
      KC_LCTL, KC_LEAD, SHGUI,   MO(2),  MO(3),    KC_LSFT, KC_SPC,  MO(1),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

  [1] = LAYOUT_ortho_4x12(
      KC_GESC, xxxxxxx, xxxxxxx, KC_F10, KC_F11,   KC_F12,  xxxxxxx, KC_PSLS, KC_7,    KC_8,    KC_9,    KC_BSPC,
      KC_TAB,  xxxxxxx, xxxxxxx, KC_F7,  KC_F8,    KC_F9,   xxxxxxx, KC_PAST, KC_4,    KC_5,    KC_6,    _______,
      KC_LGUI, xxxxxxx, xxxxxxx, KC_F4,  KC_F5,    KC_F6,   xxxxxxx, KC_PMNS, KC_1,    KC_2,    KC_3,    _______,
      KC_LCTL, xxxxxxx, _______, KC_F1,  KC_F2,    KC_F3,   KC_SPC,  _______, KC_0,    KC_DOT,  xxxxxxx, KC_EQL),

  [2] = LAYOUT_ortho_4x12(
      KC_GESC, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_BSLS, KC_LBRC, KC_RBRC, KC_DEL,
      KC_TAB,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MINS,
      KC_LGUI, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_LBRC, xxxxxxx, xxxxxxx, KC_INS,
      KC_LCTL, xxxxxxx, _______, _______, xxxxxxx, KC_LSFT, xxxxxxx, xxxxxxx, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

  [3] = LAYOUT_ortho_4x12(
      KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SLSH,
      KC_TAB,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_MINS,
      KC_LGUI, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      KC_LCTL, xxxxxxx, xxxxxxx, xxxxxxx, _______, KC_LSFT, xxxxxxx, xxxxxxx, KC_MUTE, KC_VOLD, KC_VOLU, xxxxxxx),
};

