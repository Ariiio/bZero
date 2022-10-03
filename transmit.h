#include <stdio.h>
#include "utils.h"

void trasmitNec(unsigned int adress, unsigned int command)
{
    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);
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
    delay_us(NEC_START);
    printf("GAP\n");
    delay_us(NEC_GAP);
    // send adress
    controlLed(adr_arr, adr_len);
    // send inverse adress
    controlLed(i_adr_arr, adr_len);
    // send command
    controlLed(cmd_arr, cmd_len);
    // send inverse command
    controlLed(i_cmd_arr, cmd_len);
    // finishing pulse
    printf("ON\n");
    delay_us(NEC_PULSE);
}

void transmitSamsung(unsigned int adress, unsigned int command)
{
    
}
