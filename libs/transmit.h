#include <stdio.h>
#include "utils.h"

#define LED_PIN 25
#define NEC_FREQ 38000

void trasmitNec(unsigned int adress, unsigned int command)
{
    int interval =  NEC_PULSE / 1000000 * NEC_FREQ;

    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);
    adr_len = check_len(adr_len, 8);
    cmd_len = check_len(cmd_len, 8);
    int adr_arr[adr_len];
    int cmd_arr[cmd_len];


    unsigned int invert_adr = invert_binary(adress, adr_len);
    unsigned int invert_cmd = invert_binary(command, cmd_len);
    int i_adr_arr[adr_len];
    int i_cmd_arr[cmd_len];


    int_to_bin_digit(adress, adr_len, adr_arr);
    int_to_bin_digit(command, cmd_len, cmd_arr);
    int_to_bin_digit(invert_adr, adr_len, i_adr_arr);
    int_to_bin_digit(invert_cmd, cmd_len, i_cmd_arr);

    // replace printf with led logic
    printf("PULSE\n");
    // gpio_put(LED_PIN, 1);
    delay_us(NEC_START);
    printf("GAP\n");
    // gpio_put(LED_PIN, 0);
    delay_us(NEC_GAP);
    // send adress
    control_led(adr_arr, adr_len, LED_PIN, NEC_FREQ, interval);
    // send inverse adress
    control_led(i_adr_arr, adr_len, LED_PIN, NEC_FREQ, interval);
    // send command
    control_led(cmd_arr, cmd_len, LED_PIN, NEC_FREQ, interval);
    // send inverse command
    control_led(i_cmd_arr, cmd_len, LED_PIN, NEC_FREQ, interval);
    // finishing pulse
    printf("ON\n");
    // gpio_put(LED_PIN, 1);
    delay_us(NEC_PULSE);
    printf("OFF\n");
    // gpio_put(LED_PIN, 0);
    delay_us(NEC_PULSE);
}

void transmitSamsung(unsigned int adress, unsigned int command)
{
    // 37.9KHz carrier wave (ON state is a burst of carrier with some duration, OFF is absense of it);
    // 1 Start bit (4.5ms ON, and 4.5ms OFF);
    // 32 data bits stream (data + address?);
    // bit “1” (590μs ON, 1690μs OFF) (thanks to Islam qabel,  for the more precise bit duration);
    // bit “0” (590μs ON, 590μs OFF);
    // 1 Stop bit (590μs ON, 590μs OFF);
}

void transmitRC5(unsigned int adress, unsigned int command)
{
    
}
