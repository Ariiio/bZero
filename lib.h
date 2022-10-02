#include <time.h>

void delay_us(unsigned int micro)
{
    clock_t goal = micro / 1000 + clock();
    while (goal > clock());
}