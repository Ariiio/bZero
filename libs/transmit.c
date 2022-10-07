#include "utils.c"
#include "transmit.h"

void trasmitNec(unsigned int adress, unsigned int command)
{
    // get burst iteration to show 562us
    int iterations = floor(NEC_PULSE / 1000000 * NEC_FREQ);

    // get increment needed to produce n bursts
    int increment = NEC_PULSE / iterations;

    // get bit length of adress and command
    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);

    // check if bit length is 8 (8 bits), if no add needed 0s
    adr_len = check_len(adr_len, 8);
    cmd_len = check_len(cmd_len, 8);

    // define adress and command arrays
    int adr_arr[adr_len];
    int cmd_arr[cmd_len];

    // invert binary of adress and commands
    unsigned int invert_adr = invert_binary(adress, adr_len);
    unsigned int invert_cmd = invert_binary(command, cmd_len);

    // make inverted arrays
    int i_adr_arr[adr_len];
    int i_cmd_arr[cmd_len];

    // fill arrays with bit representation of adress etc
    int_to_bin_digit(adress, adr_len, adr_arr);
    int_to_bin_digit(command, cmd_len, cmd_arr);
    int_to_bin_digit(invert_adr, adr_len, i_adr_arr);
    int_to_bin_digit(invert_cmd, cmd_len, i_cmd_arr);

    // reverse arrays
    reverse_arr(adr_arr, adr_len);
    reverse_arr(cmd_arr, cmd_len);
    reverse_arr(i_adr_arr, adr_len);
    reverse_arr(i_cmd_arr, cmd_len);

    // get burst iteration to show 9000us
    int nine = floor(NEC_START / 1000000 * NEC_FREQ);

    // get increment needed to produce n bursts
    int nine_increment = NEC_START / nine;
    pulsate(NEC_START, nine_increment);

    // gap
    sleep_us(NEC_GAP);

    // send adress
    control_led(adr_arr, adr_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send inverse adress
    control_led(i_adr_arr, adr_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send command
    control_led(cmd_arr, cmd_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // send inverse command
    control_led(i_cmd_arr, cmd_len, LED_PIN, NEC_PULSE, increment, NEC_PULSE, NEC_EXTENDED);

    // finishing pulse
    pulsate(NEC_PULSE, increment);
}

void transmitSamsung(unsigned int adress, unsigned int command)
{
    int iterations = floor(SAMSUNG_PULSE / 1000000 * SAMSUNG_FREQ);
    int increment = SAMSUNG_PULSE / iterations;

    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);
    adr_len = check_len(adr_len, 8);
    cmd_len = check_len(cmd_len, 8);
    int adr_arr[adr_len];
    int cmd_arr[cmd_len];

    int_to_bin_digit(adress, adr_len, adr_arr);
    int_to_bin_digit(command, cmd_len, cmd_arr);

    reverse_arr(adr_arr, adr_len);
    reverse_arr(cmd_arr, cmd_len);

    int start = floor(SAMSUNG_START / 1000000 * SAMSUNG_FREQ);
    int start_increment = SAMSUNG_START / start;
    pulsate(SAMSUNG_START, start_increment);

    sleep_us(SAMSUNG_START);

    // send adress
    control_led(adr_arr, adr_len, LED_PIN, SAMSUNG_PULSE, increment, SAMSUNG_PULSE, SAMSUNG_EXTENDED);
    // send command
    control_led(cmd_arr, cmd_len, LED_PIN, SAMSUNG_PULSE, increment, SAMSUNG_PULSE, SAMSUNG_EXTENDED);
    // end bit
    pulsate(SAMSUNG_PULSE, increment);
    sleep_us(SAMSUNG_PULSE);
}

void transmitRC5(unsigned int adress, unsigned int command)
{
    // get burst iteration to show 562us
    int iterations = floor(RC5_PULSE / 1000000 * RC5_FREQ);

    // get increment needed to produce n bursts
    int increment = RC5_PULSE / iterations;

    // get bit length of adress and command
    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);

    // check if bit length is 8 (8 bits), if no add needed 0s
    adr_len = check_len(adr_len, 5);
    cmd_len = check_len(cmd_len, 6;

    // define adress and command arrays
    int adr_arr[adr_len];
    int cmd_arr[cmd_len];

    // fill arrays with bit representation of adress etc
    int_to_bin_digit(adress, adr_len, adr_arr);
    int_to_bin_digit(command, cmd_len, cmd_arr);

    // send adress
    control_led_RC5(adr_arr, adr_len, LED_PIN, RC5_PULSE, increment, RC5_PULSE);

    // send command
    control_led_RC5(cmd_arr, cmd_len, LED_PIN, RC5_PULSE, increment, RC5_PULSE);
}

void transmitRC6(unsigned int adress, unsigned int command)
{
}

void transmitSIRC(unsigned int adress, unsigned int command, int bit_mode)
{
    int iterations = floor(SIRC_PULSE / 1000000 * SIRC_FREQ);
    int increment = SIRC_PULSE / iterations;

    int adr_len = bit_len(adress);
    int cmd_len = bit_len(command);
    cmd_len = check_len(adr_len, 7);

    if (bit_mode == 15)
    {
        adr_len = check_len(adr_len, 8);
    } 
    else
    {
        adr_len = check_len(adr_len, 5);
    }
    int adr_arr[adr_len];
    int cmd_arr[cmd_len];

    int_to_bin_digit(adress, adr_len, adr_arr);
    int_to_bin_digit(command, cmd_len, cmd_arr);

    reverse_arr(adr_arr, adr_len);
    reverse_arr(cmd_arr, cmd_len);

    int start = floor(SIRC_START / 1000000 * SIRC_FREQ);
    int start_increment = SIRC_START / start;
    pulsate(SIRC_START, start_increment);

    sleep_us(SIRC_PULSE);

    control_led_SIRC(cmd_arr, cmd_len, LED_PIN, SIRC_PULSE, SIRC_EXTENDED, increment, SIRC_PULSE);
    
    control_led_SIRC(adr_arr, adr_len, LED_PIN, SIRC_PULSE, SIRC_EXTENDED, increment, SIRC_PULSE);
}
