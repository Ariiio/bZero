#include <stdio.h>
#include "utils.h"

#define LED_PIN 25

void trasmitNec(unsigned int adress, unsigned int command)
{
    int iterations = floor(NEC_PULSE / 1000000 * NEC_FREQ);
    int increment = NEC_PULSE / iterations;

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
    printf("START\n");
    int nine = floor(NEC_START / 1000000 * NEC_FREQ);
    int nine_increment = NEC_START / nine;
    pulsate(NEC_START, nine_increment);

    printf("GAP\n\n\n");
    delay_us(NEC_GAP);

    // send adress
    control_led(adr_arr, adr_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send inverse adress
    control_led(i_adr_arr, adr_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send command
    control_led(cmd_arr, cmd_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send inverse command
    control_led(i_cmd_arr, cmd_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // finishing pulse
    printf("\nON\n");
    pulsate(NEC_PULSE, increment);
    printf("OFF\n");
}

void transmitSamsung(unsigned int adress, unsigned int command)
{
    int iterations = floor(SAMSUNG_PULSE / 1000000 * SAMSUNG_FREQ);
    int increment = SAMSUNG_PULSE / iterations;

    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);
    adr_len = check_len(adr_len, 16);
    cmd_len = check_len(cmd_len, 16);
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

    printf("ON");
    int start = floor(SAMSUNG_START / 1000000 * SAMSUNG_FREQ);
    int start_increment = SAMSUNG_START / start;
    pulsate(SAMSUNG_START, start_increment);
    printf("OFF\n");
    delay_us(SAMSUNG_START);
    // send adress
    control_led(adr_arr, adr_len, LED_PIN, SAMSUNG_PULSE, increment SAMSUNG_PULSE, SAMSUNG_EXTENDED);
    // send command
    control_led(cmd_arr, cmd_len, LED_PIN, SAMSUNG_PULSE, increment, SAMSUNG_PULSE, SAMSUNG_EXTENDED);
    // end bit
    pulsate(SAMSUNG_PULSE, increment);
}

void transmitRC5(unsigned int adress, unsigned int command)
{
    
}
