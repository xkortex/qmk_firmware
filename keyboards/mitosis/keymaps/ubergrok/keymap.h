#include <stdint.h>
#include QMK_KEYBOARD_H

enum mitosis_layers
  {
    _xD, // dvorak
    _xQ, // qwerty
    _xS, // symbols - red
    _xN, // numbers - blue
    _xF, // functions - purple
    _2Q  // qwerty2, electric boogaloo. allows hotkeys on native layout.
  };

enum mitosis_keycodes
  {
    KC_LAYO = SAFE_RANGE
  };

#define NUM_LAYERS 6
const bool defaultlayers[NUM_LAYERS];
const size_t defaultlayers_n;
