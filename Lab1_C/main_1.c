#include <stdio.h> 
#include "Lab1_C_header.h"


int main()
{
    int num, digit1, digit2, digit3, digit4;
    char unswer;
    unswer = ' ';

    while (unswer != 'n')
    {
        printf("Do you wanna change your four-digit number? (y or n) \n");

        scanf("%c", unswer); 
        if (unswer == 'y')
        {
            printf("Enter  your four-digit number \n");
            scanf("%d", &num);

            if (num > 999 && num < 10000)
            {
                digit4 = Digit4(num);
                digit3 = Digit3(num);
                digit2 = Digit2(num);
                digit1 = Digit1(num);

                if (digit3 == 0)
                {
                    num = digit4 * 100 + digit1 * 10 + digit2;
                }
                else
                {
                    num = digit3 * 1000 + digit4 * 100 + digit1 * 10 + digit2;
                }
                printf ("num = %d\n", num);
            }
            else
            {
                printf ("Wrong numder, try again");
                continue;
            }
        }
        else if (unswer == 'n')
        {
            printf("Ok, bye");
        }
        else
        {
            printf("Wrong imput, try again \n");
        }
    }
}

int Digit4(int _num)
{
    int digit4 = _num % 10;
    return digit4;
}

int Digit3(int _num)
{
    int digit3 = (_num % 100 -  Digit4 (_num)) / 10;
    return digit3;
}

int Digit2(int _num)
{
    int digit2 = (_num % 1000 - Digit3(_num) * 10 - Digit4(_num)) / 100;
    return digit2;
}

int Digit1 (int _num)
{
    int digit1 = (_num - Digit4(_num) - Digit3(_num) * 10 - Digit2(_num) * 100) / 1000;
    return digit1;
}
