#include <stdio.h>
#include "pico/stdlib.h"
#include "libs/transmit/samsung/samsung_transmit.h"

#define LED_PIN 13
#define BTN_PIN 12

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_down(BTN_PIN);

    PIO pio = pio0;
    int sm = samsung_tx_init(pio, 25);

    if (sm == -1)
    {
        return -1;
    }

    uint8_t address = 0x07;
    uint8_t data = 0xE6;

    while (true)
    {
        if (gpio_get(BTN_PIN))
        {
            samsung_tx(pio, sm, address, data);
        }
    }

    return 0;
}
