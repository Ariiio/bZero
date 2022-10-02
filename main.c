#include <stdio.h>
#include <time.h>

void delay_us(unsigned int micro);

int main()
{
    printf("Test");

    return 0;
}

void delay_us(unsigned int micro)
{
    clock_t goal = micro / 1000 + clock();
    while (goal > clock());
}
