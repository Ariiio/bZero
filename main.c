#include <stdio.h>
#include <time.h>

void delay_us(unsigned int micro);

int main()
{
    printf("ON\n");
    delay_us(9000);
    printf("OFF\n");
    delay_us(4500);

    return 0;
}

void delay_us(unsigned int micro)
{
    clock_t goal = micro / 1000 + clock();
    while (goal > clock()); //bruh
}
