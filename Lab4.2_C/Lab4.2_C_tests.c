#include "Lab4.2_C_header.h"
#include <assert.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int Tests()
{
    char text[] = "BOBA SDFSLSDRVLDF COCAT SDFGJD";
    assert(LineLength(text) == 30);
    assert(ShowPseudoRussian(text) == 1);
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