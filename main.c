#include <stdio.h>
#include "libs/transmit.c"
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_down(BTN_PIN);

    uint adress = 0x07;
    uint command = 0xE6;

    while (true)
    {    
        if (gpio_get(BTN_PIN))
        {
            transmitSamsung(adress, command);
            sleep_ms(50);
            transmitSamsung(adress, command);
            sleep_ms(50);
            transmitSamsung(adress, 0x02);
            sleep_ms(250);
        }
    }
    
    // unsigned int adress = 0x59;
    // unsigned int command = 0x16;
    
    // transmitSamsung(adress, command);
    // sleep_ms(4000);
    

    // unsigned int adress = 0x01;
    // unsigned int command = 0x15;

    // transmitSIRC(adress, command, 12);

    return 0;
}
