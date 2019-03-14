#include <stdint.h>
#include QMK_KEYBOARD_H

/* Getting one handed hotkeys is kind of a pain in dvorak, especially
 * cut/copy/paste. My current solution is to make a second querty
 * layer, all the way at the top, that pressing LQ_ctrl jumps to
 * as a temporary boost */


enum mitosis_layers
  {
    _xD=0, // dvorak               x01         01
    _xQ=1, // qwerty               x02         10
    _bP,   // programmer mode      x04        100
    _sR,   // symbols / nav - red  x08       1000
    _nB,   // numbers / Fkey- blue x10     1 0000
    _xF,   // functions - purple   x28    10 1000     depending on order, it "inherits" lower when using TT
           //                      x30    11 0000
    _2Q    // qwerty2              x40   100 0000
  };


#define LAY_RED 0x08u
#define LAY_BLU 0x10u
#define LAY_FN  0x20u
#define LAY_Q2  0x40u
#define TX_LED  0b00100000u

enum mitosis_keycodes
  {
    KC_LAYO = SAFE_RANGE
  };

#define NUM_LAYERS 7
const bool defaultlayers[NUM_LAYERS];
const size_t defaultlayers_n;
