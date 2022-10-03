#include <time.h>
#include <math.h>

#define NEC_START 9000000
#define NEC_GAP 4500000
#define NEC_PULSE 562000
#define NEC_EXTENDED 1687000

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

void control_led(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!array[i])
        {
            printf("Sent 0\n");
            delay_us(NEC_PULSE);
            printf("OFF\n");
            delay_us(NEC_PULSE);
        }
        if (array[i])
        {
            printf("Sent 1\n");
            delay_us(NEC_PULSE);
            printf("OFF\n");
            delay_us(NEC_EXTENDED);
        }
    }

    printf("\n\n\n");
}

int check_len(int len)
{
    int diff = 8 - len;
    if (diff != 0)
    {
        len += diff;
    }
    
    return len;
}
