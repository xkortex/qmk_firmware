#include QMK_KEYBOARD_H

enum mitosis_layers
  {
    _xQ, // qwerty
    _xC, // colemak
    _xD, // dvorak
    _xW, // workman
    _xS, // symbols - red
    _xN, // numbers - blue
    _xF  // functions - purple
  };

enum mitosis_keycodes
  {
    KC_LAYO = SAFE_RANGE
  };

const bool defaultlayers[7];
const size_t defaultlayers_n;
