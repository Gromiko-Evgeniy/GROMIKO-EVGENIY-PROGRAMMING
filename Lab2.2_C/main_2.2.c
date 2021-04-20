#include <stdio.h>
#include <math.h>
#include "Lab2.2_C_header.h"
#include "conio.h"


int main (void)
{
    printf ("Enter x, x = ");
    float x = EnterX();
    float e = 0.05;
    int n = 0;
    float value = 0;
    Iteration(x, e, n, value);
    value = 0;
    n = 0;
    Recursion(x, e, n, value);
      _getch();
    return 0;
}

double Fact(int N)
{
    if(N < 0) 
        return 0; 
    if (N == 0) 
        return 1;
    else 
        return N * Fact(N - 1); 
}

float EnterX()
{
    float x;
    while(!scanf("%f", &x) || x < 0 || x > 6.2) 
    {
        printf("Error input. Try again\n");
        fflush(stdin);
    }
      _getch();
    return x;
}

int Iteration(int x, float e, int n, float value)
{
     while (fabs(sin(x) - value) >= e)
     {
         n++;
         value += pow(-1, n-1) * pow(x, 2*n-1)/Fact(2*n - 1);
     }
     printf("Result sin x: %f\tResult: %f\tStep: %d\n", sin(x), value, n);
       _getch();
     return n;
}

int Recursion(int x, float e, int n, float value)
{
     n++;
     value += pow(-1, n-1) * pow(x, 2*n-1)/Fact(2*n - 1);
     if (fabs(sin(x) - value) >= e)
     {
        return Recursion(x, e, n, value);
     } else
     {
         printf("Result sin x: %f\tResult: %f\tStep: %d\n", sin(x), value, n);
           _getch();
         return n;
     }
}