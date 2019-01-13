#include "mitosis.h"

void uart_init(void) {
	SERIAL_UART_INIT();
}

void led_init(void) {
  // LEDs are:
  //
  // PB0 (Pro micro RX LED)
  // PD5 (Pro micro TX LED)
  // PF5 (Mitosis RGB LED Red component)
  // PD1 (Mitosis RGB LED Green component)
  // PF4 (Mitosis RGB LED Blue component)
  DDRB  |= (1<<0);
  PORTB |= (1<<0);
#ifdef MITOSIS_DATAGROK_I2CHACK
  DDRD  |= (1<<4) | (1<<5); // Pin to green, set as output
  PORTD |= (1<<4) | (1<<5); // Turn it off
#else
  DDRD  |= (1<<1) | (1<<5); // Pin to green, set as output
  PORTD |= (1<<1) | (1<<5); // Turn it off
#endif
  DDRF  |= (1<<4) | (1<<5); // Pins to red and blue, set as output
  PORTF |= (1<<4) | (1<<5); // Turn them off
}

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	uart_init();
	led_init();
}

#ifdef SWAP_HANDS_ENABLE
__attribute__ ((weak))
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
{{9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
{{9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
{{9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
{{9, 3}, {8, 3}, {7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
{{9, 4}, {8, 4}, {7, 4}, {6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
};
#endif
