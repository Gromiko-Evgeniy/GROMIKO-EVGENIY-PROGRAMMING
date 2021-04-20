#include "Lab2_C_header.h"
#include <assert.h>
#include <stdio.h>

int Test()
{
    assert(SMSprice(10) == 2);
    assert(TheSameNetworkCallPrice(10) == 5);
    assert(OtherNetworkCallPrice(10) == 10);
    assert(UrbanNetworkCallPrice(10) == 1);
}

#undef main

int main()
{
    Test();
    printf("program have tested");

    return 0;
}
