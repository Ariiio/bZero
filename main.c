#include <stdio.h>
// #include "utils.h"
#include "transmit.h"

int main(int argc, char *argv[])
{
    unsigned int adress = 0xAD;
    unsigned int command = 0xCD;

    trasmitNec(adress, command);

    return 0;
}
