#include <stdint.h>
#include QMK_KEYBOARD_H

enum mitosis_layers
  {
    _xQ, // qwerty
    _xC, // colemak
    _xD, // dvorak
    _xW, // workman
    _xS, // symbols - red
    _xN, // numbers - blue
    _xF, // functions - purple
    _2Q  // qwerty2, electric boogaloo. allows hotkeys on native layout.
  };

enum mitosis_keycodes
  {
    KC_LAYO = SAFE_RANGE
  };

#define NUM_LAYERS 8
const bool defaultlayers[NUM_LAYERS];
const size_t defaultlayers_n;
