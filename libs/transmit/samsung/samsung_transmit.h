#include "pico/stdlib.h"
#include "hardware/pio.h"

int samsung_tx_init(PIO, uint);
void samsung_tx(PIO, int, uint8_t, uint8_t);
void samsung_tx_extended(PIO, int, uint16_t, uint16_t);
void samsung_tx_raw(PIO, int, uint32_t);