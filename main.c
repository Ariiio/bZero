#include <stdio.h>
#include "libs/transmit.h"
// #include "pico/stdlib.h"

int main()
{
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);

    unsigned int adress = 0x00;
    unsigned int command = 0x1A;
    
    trasmitNec(adress, command);
    
    // unsigned int adress = 0xE579;
    // unsigned int command = 0x8549;

    // transmitSamsung(adress, command);

    return 0;
}
