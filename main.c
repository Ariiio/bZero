#include <stdio.h>
#include "libs/transmit.h"
// #include "pico/stdlib.h"

int main()
{
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);

    // unsigned int adress = 0x59;
    // unsigned int command = 0x16;
    
    // trasmitNec(adress, command);
    
    // unsigned int adress = 0xE579;
    // unsigned int command = 0x8549;

    // transmitSamsung(adress, command);

    unsigned int adress = 0x01;
    unsigned int command = 0x13;

    transmitSIRC(adress, command, 12);

    return 0;
}
