#include <print.h>
#include "aux.h"

void vprint( void ) { print("vprint"); }

void layer_print( uint32_t layer) {
  print(" layr");
  print_hex16(layer);
}