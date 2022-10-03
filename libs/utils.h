#include <time.h>
#include <math.h>
// #include "pico/stdlib.h"

#define NEC_START 9000
#define NEC_GAP 4500
#define NEC_PULSE 562.0
#define NEC_EXTENDED 1687

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

void pulsate(int freq, int interval)
{
    for (int i = 0; i < freq; i += interval)
    {
        delay_us(interval / 4);
        delay_us(interval / 4);
    }
    
}

void control_led(int array[], int len, int led, int freq, int interval)
{
    for (int i = 0; i < len; i++)
    {
        if (!array[i])
        {
            printf("Sent 0\n");
            // gpio_put(led, 1);
            pulsate(freq, interval);
            printf("OFF\n");
            // gpio_put(led, 0);
            delay_us(NEC_PULSE);
        }
        if (array[i])
        {
            printf("Sent 1\n");
            // gpio_put(led, 1);
            pulsate(freq, interval);
            printf("OFF\n");
            // gpio_put(led, 0);
            delay_us(NEC_EXTENDED);
        }
    }

    printf("\n\n\n");
}

// void sussy()
// {
//     printf("ON");
//     pulse(36000, 32); // (889 / 1000000) * 36000
//     printf("OFF");
//     delay_us(889);
// }


int check_len(int len, int bits)
{
    int diff = bits - len;
    if (diff != 0)
    {
        len += diff;
    }
    
    return len;
}
