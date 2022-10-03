#include <stdio.h>
#include "transmit.h"

int main(int argc)
{
    unsigned int adress = 0x01;
    unsigned int command = 0x1A;

    trasmitNec(adress, command);
    
    return 0;
}
