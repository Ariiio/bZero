#include <math.h>
#include "pico/stdlib.h"
#include "utils.h"

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
        gpio_put(LED_PIN, 1);
        sleep_us(floor(increment / 4));
        gpio_put(LED_PIN, 0);
        sleep_us(floor(increment / 4));
    }
}

void control_led(int array[], int len, int led, int freq, int interval, int zDelay, int oDelay)
{
    for (int i = 0; i < len; i++)
    {
        if (!array[i])
        {
            pulsate(freq, interval);
            sleep_us(zDelay);
        }
        if (array[i])
        {
            pulsate(freq, interval);
            sleep_us(oDelay);
        }
    }
}

void control_led_SIRC(int array[], int len, int led, int zFreq, int oFreq, int interval, int delay)
{
    for (int i = 0; i < len; i++)
    {
        if (!array[i])
        {
            pulsate(zFreq, interval);
            sleep_us(delay);
        }
        if (array[i])
        {
            pulsate(oFreq, interval);
            sleep_us(delay);
        }
    }
}

// void LORENZMACHWAS()
// {
//     printf("ON");
//     pulse(36000, 32); // (889 / 1000000) * 36000
//     printf("OFF");
//     sleep_us(889);
// }

void reverse_arr(int arr[], int n)
{
    int aux[n];

    for (int i = 0; i < n; i++)
    {
        aux[n - 1 - i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = aux[i];
    }
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