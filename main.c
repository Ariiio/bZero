#include <stdio.h>
#include "libs/transmit.h"

int main()
{
    unsigned int adress = 0x00;
    unsigned int command = 0x1A;

    trasmitNec(adress, command);
    
    return 0;
}
