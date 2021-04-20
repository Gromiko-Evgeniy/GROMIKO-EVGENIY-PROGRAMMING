#include "Lab1_C_header.h"
#include <assert.h>
#include <stdio.h>


int Test()
{
    assert(Digit4 (5467) == 7);
    assert(Digit3 (5467) == 6);
    assert(Digit2 (5467) == 4);
    assert(Digit1 (5467) == 5);

    return 0;
}

#undef main

int main()
{
    Test();
    printf("program have tested");

    return 0;
}
