#include "Lab2.2_C_header.h"
#include <assert.h>
#include <stdio.h>


int Tests()
{
    assert(Fact(6) - 720 < 0.000001);
    assert(Iteration(5, 0.05, 0, 0) == 7);
    assert(Recursion(2.3, 0.05, 0, 0) == 3);

    return 0;
}

#undef main
int main()
{
    Tests();
    printf("program has tasted");
    
    return 0;
}
