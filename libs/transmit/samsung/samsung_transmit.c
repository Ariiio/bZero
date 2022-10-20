#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "samsung_transmit.h"
#include "samsung_carrier_burst.pio.h"
#include "samsung_carrier_control.pio.h"

int samsung_tx_init(PIO pio, uint pin)
{
    uint carrier_burst_offset = pio_add_program(pio, &samsung_carrier_burst_program);
    int carrier_burst_sm = pio_claim_unused_sm(pio, true);

    if (carrier_burst_sm == -1)
    {
        return -1;
    }

    samsung_carrier_burst_program_init(pio, carrier_burst_sm, carrier_burst_offset, pin, 38.222e3);

    uint carrier_control_offset = pio_add_program(pio, &samsung_carrier_control_program);
    int carrier_control_sm = pio_claim_unused_sm(pio, true);

    if (carrier_control_sm == -1)
    {
        return -1;
    }

    samsung_carrier_control_program_init(pio, carrier_control_sm, carrier_control_offset, 2 * (1 / 562.5e-6), 32);

    return carrier_control_sm;
}

void samsung_tx(PIO pio, int sm, uint8_t address, uint8_t data)
{
    pio_sm_put_blocking(pio, sm, address | address | data << 16 | (data ^ 0xff) << 24);
}

void samsung_tx_extended(PIO pio, int sm, uint16_t address, uint16_t data)
{
    pio_sm_put_blocking(pio, sm, address | data << 16);
}

void samsung_tx_raw(PIO pio, int sm, uint32_t data)
{
    pio_sm_put_blocking(pio, sm, data);
}
