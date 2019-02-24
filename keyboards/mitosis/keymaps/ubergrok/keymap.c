#include "keymap.h"
#include "feature_cdeq.h"
#include "feature_layout_rotate.h"

// clion spoofing
//#include "stdint.h"
//#include "../../config.h"
//#include "keymap.h"
#include "mitosis.h"
#include "aux.h"

#ifdef AUDIO_ENABLE
#include "audio.h"
#ifdef DEFAULT_LAYER_SONGS
extern float default_layer_songs[][16][2];
#endif
#endif

// Setting MITOSIS_DATAGROK_BOTTOMSPACE in rules.mk will swap the upper and
// lower center four thumb-keys. See keymaps/datagrok/rules.mk.
#ifdef MITOSIS_DATAGROK_BOTTOMSPACE
#undef LAYOUT
#define LAYOUT LAYOUT_bottomspace
#endif

// Fillers to make layering more clear
#define _______ KC_TRNS // Transparent

// I don't use Japanese myself, but I've placed henkan 変換 and muhenkan 無変換
// in my layout to act as left and right HYPER

// Momentary tri-state layers. Mitosis default keymap does this too but employs
// new keymappings and a bunch of conditional code. This simpler keymap
// accomplishes it but with a small quirk: triggering both layers then releasing
// one out-of-order will leave the tri-state triggered until the other is
// released. Which doesn't bother me.

// The weird /*,*/ comments are a hack to get slightly better automatic
// tabulation in my editor.

// We use Space Cadet KC_RSPC to get _ on right shift. See config.h for details.

// Layer Qwerty Left Modifier Macros
#define LQ_LCTL LM(_2Q,MOD_LCTL)
//#define LQ_LCTL KC_LCTL
#define LQ_LALT LM(_xQ,KC_LALT)
#define SHIFTAB MT(MOD_LSFT, KC_TAB)

const uint16_t PROGMEM keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {

  [_xD] = LAYOUT(
    KC_QUOT, KC_COMM,    KC_DOT,  KC_P,    KC_Y,           KC_F,    KC_G,    KC_C,    KC_R,     KC_L,
    KC_A,    KC_O,       KC_E,    KC_U,    KC_I,           KC_D,    KC_H,    KC_T,    KC_N,     KC_S,
    KC_SCLN, KC_Q,       KC_J,    KC_K,    KC_X,           KC_B,    KC_M,    KC_W,    KC_V,     KC_Z,
    /*,   */ KC_LGUI,    KC_LSHIFT, MO(_xS), KC_BSPC,        KC_RSPC, MO(_xN), KC_RSHIFT, KC_LAYO,
    /*,   */ KC_HENK,    LQ_LCTL, MO(_xN), KC_SPC,         SHIFTAB, MO(_xS), KC_RCTL, KC_MHEN),

  [_xQ] = LAYOUT(
    KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
    KC_A,    KC_S,       KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_QUOT,
    /*,   */ _______,    _______, _______, _______,        _______, _______, _______, _______,
    /*,   */ _______,    _______, _______, _______,        _______, _______, _______, _______),

      /* RED */
  [_xS] = LAYOUT(
    KC_ESC,  KC_END ,    KC_UP,   KC_HOME, KC_PGUP,        KC_PLUS, KC_CIRC, KC_AMPR, KC_PERC,  KC_BSPC,
    _______, KC_LEFT,    KC_DOWN, KC_RGHT, KC_PGDN,        KC_PIPE, KC_AT,   KC_DLR,  KC_HASH,  KC_ENT,
    KC_BSLS, KC_LABK,    KC_LCBR, KC_LPRN, KC_LBRC,        KC_RBRC, KC_RPRN, KC_RCBR, KC_RABK,  KC_SLSH,
    /*,      */ _______, _______, _______, KC_DEL,         _______, _______, _______, _______,
    /*,      */ _______, LQ_LCTL, _______, _______,        _______, TT(_xF), _______, _______),

      /* BLUE */
  [_xN] = LAYOUT(
    KC_ESC,  KC_F7,      KC_F8,   KC_F9,   KC_F10,         KC_PPLS, KC_7,    KC_8,    KC_9,     KC_KP_DOT,
    KC_SLCK, KC_F4,      KC_F5,   KC_F6,   KC_F11,         KC_NLCK, KC_4,    KC_5,    KC_6,     KC_PENT,
    KC_PAUS, KC_F1,      KC_F2,   KC_F3,   KC_F12,         KC_PAST, KC_1,    KC_2,    KC_3,     KC_PSLS,
    /*,      */ _______, _______, _______, _______,        _______, TT(_xF), KC_0,    KC_DOT,
    /*,      */ _______, LQ_LCTL, _______, _______,        _______, _______, _______, _______),

      /* Purple */
  [_xF] = LAYOUT(
    RESET,   KC_INS,     KC_PGUP, DEBUG,   KC_VOLU,        KC_PPLS, KC_P7,   KC_P8,   KC_P9,    KC_PMNS,
    CK_TOGG, KC_HOME,    KC_PGDN, KC_END,  KC_VOLD,        KC_NLCK, KC_P4,   KC_P5,   KC_P6,    KC_PENT,
    KC_LAYO, KC_MPRV,    KC_MPLY, KC_MNXT, KC_MUTE,        KC_PAST, KC_P1,   KC_P2,   KC_P3,    KC_PSLS,
    /*,      */ _______, _______, _______, _______,        _______, _______, KC_P0,   KC_PDOT,
    /*,      */ _______, LQ_LCTL, _______, _______,        _______, _______, _______, _______),

      /* Over-qwerty for hotkeys */
  [_2Q] = LAYOUT(
    KC_Q,    KC_W,       KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
    KC_A,    KC_S,       KC_D,    KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
    KC_Z,    KC_X,       KC_C,    KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_QUOT,
    /*,   */ _______,    _______, _______, _______,        _______, _______, _______, _______,
    /*,   */ _______,    _______, _______, _______,        _______, _______, _______, _______),
};

const bool defaultlayers[NUM_LAYERS] = {
  [_xD] = true,
  [_xQ] = true,
  [_xS] = false,
  [_xN] = false,
  [_xF] = false,
  [_2Q] = false
};
const size_t defaultlayers_n = sizeof(defaultlayers) / sizeof(defaultlayers[0]);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return \
    process_record_cdeq(keycode, record) && \
    process_record_layout(keycode, record);
}

// Set the bits of A selected by MASK to the corresponding bits of B
#define setbits(A, B, MASK) A = ((A) & ((B) | ~(MASK))) | ((B) & (MASK))
#define RED_BIT 0b00100000
#define BLU_BIT 0b00010000
#define GRN_BIT 0b00110000

void led_set_user(uint8_t usb_leds) {
  // A simple (but technically inaccurate) model of the momentary layer state:
  // Red layer active -> indicator = red
  // Blue layer active -> indicator = blue
  // Purple layer active -> indicator = purple
  // the Pro Micro tx LED displays Num Lock status.
  //
  // Workman layout active -> indicator = green
  // Workman red layer -> indicator = yellow (red + green)
  // Workman blue layer -> indicator = cyan (blue + green)
  // Workman purple layer -> indicator = white (red + blue + green)

  // Bit #            7     6     5     4     3     2     1     0
  // layer_state: [     | _xF | _xN | _xS | _xW | _xD | _xC | _xQ ]
  // usb_led      [     |     |     |kana |cmps |scrl |caps | num ]
  // PORTB:       [  NC |  10 |   9 |   8 |  14 |  16 |  15 |rxled]
  // PORTC:       [  NC |   5 |     |     |     |     |     |     ]
  // PORTD:       [   6 |  NC |txled| grn+| tx* | rx* | sda+| scl ]
  // PORTE:       [     |   7 |     |     |     |     |     |     ]
  // PORTF:       [  a0 |  a1 | red | blu |     |     |  NC |  NC ]
  //
  // * PD3 and PD2 are transmit and receive for USART1 which is how the pro
  //   micro communicates with the wireless module.
  // + I moved the green LED from PD1 to PD4; see rules.mk.
  // PD0 is connected to the pairing button and p29 on the wireless module.
  // PF0,PF1,PB7,PC7,PD6 are not broken out by the pro micro board. I don't understand why.
  // PB1-PB6,PD4,PD5,PD6,PF6,PF7 are not connected to the Mitosis receiver
  // board. Each may be connected to an LED by way of a resistor (4.7k to
  // match the others) for a total of 14 additional indicators.

//  uint8_t adj_layer = layer_state + 2;
  layer_print(layer_state);
//  uprint("ledset %d ", layer_state);
  uint8_t portd_bits = 0;
  uint8_t portf_bits = 0;
  /*
  portf_bits = \
    ((adj_layer|default_layer_state)&0b01100000)>>1 | \
    ((adj_layer|default_layer_state)&0b00010000)<<1 | \
    ((adj_layer|default_layer_state)&0b01000000)>>2;
    */
  uint8_t layer_mask = layer_state & 1;
  if (layer_mask) {
    portf_bits |= RED_BIT;
  } else {
    portf_bits |= BLU_BIT;
  }
  /*
  switch (layer_state) {
    case 1:
      portf_bits |= RED_BIT;
//      break;
    case _xS:
      portf_bits |= RED_BIT;
      break;
    case _xN:
      portf_bits |= RED_BIT;
      break;
    default:
//      portf_bits |= RED_BIT;
//      portf_bits |= BLU_BIT;

      break;
  }
   */

  // negated because for ports 0=LED on.
  setbits(PORTF, ~portf_bits, 0b00110000);
//  PORTF &= ~(1<<5);
//  PORTF &= ~(1<<4);
//  PORTD &= ~(1<<1);
#ifdef MITOSIS_DATAGROK_I2CHACK
  portd_bits = \
    (usb_leds&0b1)<<5 | \
    ((adj_layer|default_layer_state)&0b1000)<<1;
  setbits(PORTD, ~portd_bits, 0b00110000);
#else
  portd_bits = 0;//0b00100010;
  /*
  portd_bits =
    (usb_leds&0b1)<<5 |
    ((adj_layer|default_layer_state)&0b1000)>>2;
    */
  setbits(PORTD, ~portd_bits, 0b00100010);
#endif
}

// vim: set sw=2 et:
