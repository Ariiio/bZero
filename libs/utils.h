#include <time.h>
#include <math.h>
// #include "pico/stdlib.h"

#define NEC_FREQ 38000
#define NEC_START 9000.0
#define NEC_GAP 4500.0
#define NEC_PULSE 562.0
#define NEC_EXTENDED 1687.0

#define SAMSUNG_FREQ 37900
#define SAMSUNG_START 4500.0
#define SAMSUNG_PULSE 590.0
#define SAMSUNG_EXTENDED 1690.0

#define RC5_PULSE 889.0

void delay_us(unsigned int mili)
{
    clock_t goal = mili / 1000 + clock();
    while (goal > clock());
}

int bit_len(unsigned int n)
{
    return floor(log(n) / log(2)) + 1;
}

void int_to_bin_digit(unsigned int in, int len_digitis, int *out_digit)
{
    unsigned int mask = 1U << (len_digitis - 1);
    int i;
    for (i = 0; i < len_digitis; i++)
    {
        out_digit[i] = (in & mask) ? 1 : 0;
        in <<= 1;
    }
}

int invert_binary(int num, int bits)
{
    int mask = 0;
    int bitval = 1;

    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    return num ^ mask;
}

void pulsate(int freq, int increment)
{
    for (int i = increment; i < freq; i += increment)
    {
        // printf("ON\n");
        // gpio_put(led, 1);
        delay_us(floor(increment / 4));
        // printf("OFF\n");
        // gpio_put(led, 0);
        delay_us(floor(increment / 4));
    }
    
}

void control_led(int array[], int len, int led, int freq, int interval, int zDelay, int oDelay)
{
    for (int i = 0; i < len; i++)
    {
        if (!array[i])
        {
            printf("Sent 0\n");
            pulsate(freq, interval);
            printf("OFF\n");
            // gpio_put(led, 0);
            delay_us(zDelay);
        }
        if (array[i])
        {
            printf("Sent 1\n");
            pulsate(freq, interval);
            printf("OFF\n");
            // gpio_put(led, 0);
            delay_us(oDelay);
        }
    }
    printf("\n");
}

void LORENZMACHWAS()
{
    printf("ON");
    pulse(36000, 32); // (889 / 1000000) * 36000
    printf("OFF");
    delay_us(889);
}


int check_len(int len, int bits)
{
    int diff = bits - len;
    if (diff != 0)
    {
        len += diff;
    }
    
    return len;
}
