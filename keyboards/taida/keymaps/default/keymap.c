// #include QMK_KEYBOARD_H

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT(KC_LGUI)
// };

#include QMK_KEYBOARD_H

// #include "quantum.h"

// // clang-format off
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   // keymap for default
//   [0] = LAYOUT_universal(
//     KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
//     KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
//     KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
//     KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, KC_RSFT
//   ),

//   [1] = LAYOUT_universal(
//     KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
//     KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
//     S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
//     KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
//   ),

//   [2] = LAYOUT_universal(
//     KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
//    S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                            S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
//     KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                           S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
//     KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
//   ),

//   [3] = LAYOUT_universal(
//     RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
//     RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
//     RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
//     QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
//   ),
// };
// // clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Auto enable scroll mode when the highest layer is 3
//     keyball_set_scroll_mode(get_highest_layer(state) == 3);
//     return state;
// }

// #ifdef OLED_ENABLE

// #    include "lib/oledkit/oledkit.h"

// void oledkit_render_info_user(void) {
//     keyball_oled_render_keyinfo();
//     keyball_oled_render_ballinfo();
//     keyball_oled_render_layerinfo();
// }
// #endif



// Defines the keycodes used by our macros in process_record_user
#define _ZERO 0
#define _ONE 1
#define _TWO 2
#define _THREE 3
#define _FOUR 4
#define _FIVE 5
#define _SIX 16
#define WIN_H LALT(KC_GRV)
#define MAC_H LGUI(KC_GRV)
#define RESET QK_BOOT

enum custom_keycodes {
    ZERO = SAFE_RANGE,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ZERO
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | Z/ctl| X/ctl|   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  | / Alt|
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |  TWO |  Spc |  Sft |           | BkSp |Ent/GUI| ONE |
 *               `--------------------'           `--------------------'
 */
[_ZERO] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    MT(MOD_LCTL, KC_Z),    MT(MOD_LCTL, KC_X),    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  MT(MOD_RALT, KC_SLSH),
                    TWO,     KC_SPC,  KC_LSFT,      KC_BSPC, MT(MOD_LGUI, KC_ENT), ONE
),

/* ONE
 *
 * ,----------------------------------.             ,----------------------------------.
 * |  Esc |   !  |   @  |   #  |   $  |             |   +  |  F1  |  F2  |  F3  |  F4  |
 * |------+------+------+------+------|             |------|------+------+------+------|
 * |  Tab |   %  |   *  |   &  |   '  |             |   =  |  F5  |  F6  |  F7  |  F8  |
 * |------+------+------+------+------|             |------|------+------+------+------|
 * | Ctrl |   `  |   ^  |   \  |  Sft |             |   -  |  F9  | F10  |  F11 |  SIX |
 * `-------------+------+------+------|             |------|------+------+------+------'
 *               | THREE|  Spc |  Sft |             |  DEL |Ent/GUI|     |
 *               `--------------------'             `--------------------'
 */
[_ONE] = LAYOUT(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,        KC_PLUS, KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,
    KC_TAB,  KC_PERC, KC_ASTR, KC_AMPR, KC_QUOT,       KC_EQL , KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 ,
    KC_LCTL, KC_GRV , KC_CIRC, KC_BSLS, KC_LSFT,       KC_MINS, KC_F9 ,  KC_F10,  KC_F11,  SIX,
                    THREE, KC_SPC,  KC_LSFT,       KC_DEL,  MT(MOD_LGUI, KC_ENT), _______
),

/* TWO
 *
 * ,----------------------------------.         ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |         |   '  |      |   ↑  |   [  |   ]  |
 * |------+------+------+------+------|         |------+------+------+------+------|
 * |   6  |   7  |   8  |   9  |   0  |         |   =  |  ←   |  (   |   →  |   )  |
 * |------+------+------+------+------|         |------+------+------+------+------|
 * | Ctrl | Tab  |  Alt | Sft  | FIVE |         |   -  |      |   ↓  |   {  |   }  |
 * `-------------+------+------+------|         |------+------+------+------+------'
 *               |      |  Spc |  Sft |         | Del  |Ent/GUI|FOUR |
 *               `--------------------'         `--------------------'
 */
[_TWO] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_QUOT, KC_NO, KC_UP ,   KC_LBRC,  KC_RBRC,
    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_EQL , KC_LEFT, KC_LPRN,  KC_RIGHT, KC_RPRN,
    KC_LCTL, KC_TAB,  KC_RALT, KC_LSFT, FIVE,       KC_MINS, KC_NO, KC_DOWN,  KC_LCBR,  KC_RCBR,
                    _______, KC_SPC,  KC_LSFT,    KC_DEL, MT(MOD_LGUI, KC_ENT), FOUR
),

/* THREE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |  Alt | Ctrl |  GUI |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |  Spc |  Sft |           | BkSp |  Ent |      |
 *               `--------------------'           `--------------------'
 */
[_THREE] =  LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_RALT, KC_LCTL, KC_LGUI,
                    _______, KC_SPC,  KC_LSFT,      KC_BSPC, KC_ENT, _______
),

/* FOUR
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |      |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[_FOUR] =  LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                KC_NO, KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO
),

/* FIVE
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      | nrm  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      | swp  |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |WIN_H |MAC_H |      |      |      |           | Alt  |   ~  |      |      |      |
 * `-------------+------+------+------|           |------+------+------+------+------'
 *               |      |      |RESET |           |      |      |      |
 *               `--------------------'           `--------------------'
 */
[_FIVE] =  LAYOUT(
    KC_NO, KC_NO, KC_NO, KC_NO, LCG_NRM,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, LCG_SWP,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    WIN_H, MAC_H, KC_NO, KC_NO, KC_NO,      KC_RALT, KC_TILD, KC_NO, KC_NO, KC_NO,
                    KC_NO, KC_NO, RESET,      KC_NO,  KC_NO, KC_NO
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ZERO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ZERO);
            }
            return false;
            break;
        case ONE:
            if (record->event.pressed) {
                layer_on(_ONE);
                update_tri_layer(_ONE, _THREE, _SIX);
            } else {
                layer_off(_ONE);
                update_tri_layer(_ONE, _THREE, _SIX);
            }
            return false;
            break;
        case TWO:
            if (record->event.pressed) {
                layer_on(_TWO);
                update_tri_layer(_TWO, _FOUR, _FIVE);
            } else {
                layer_off(_TWO);
                update_tri_layer(_TWO, _FOUR, _FIVE);
            }
            return false;
            break;
        case THREE:
            if (record->event.pressed) {
                layer_on(_THREE);
            } else {
                layer_off(_THREE);
            }
            return false;
            break;
        case FOUR:
            if (record->event.pressed) {
                layer_on(_FOUR);
            } else {
                layer_off(_FOUR);
            }
            return false;
            break;
        case FIVE:
            if (record->event.pressed) {
                layer_on(_FIVE);
            } else {
                layer_off(_FIVE);
            }
            break;
    }
    return true;
}
