#include <stdio.h>
#include <time.h>

void delay_us(unsigned int mili)
{
    clock_t goal = mili / 1000 + clock();
    while (goal > clock());
}

void pulsate(int freq, int interval)
{
    for (int i = 0; i < freq; i += interval)
    {
        delay_us(interval / 4);
        delay_us(interval / 4);
    }
}

int main()
{
    pulsate(38000, 21);

    return 0;
}