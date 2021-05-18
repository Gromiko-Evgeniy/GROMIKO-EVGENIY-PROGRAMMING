#include "Lab4.1_C_header.h"
#include <assert.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Tests()
{
    char text[] = "a(b(c)d)e";
    assert(LineLength(text) == 9);
    assert(RemoveUnnecessary(text) == 1);
    return 0;
}

#undef main
int main()
{
    Tests();
    printf("program has tasted");
    _getch();

    return 0;
}