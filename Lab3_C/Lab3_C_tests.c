#include "Lab3_C_header.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int Tests()
{
    int columns = 5, lines = 4, squareSize =3, i, j;

    int **matrix = (int**)malloc(lines * sizeof(int*));
    for(i = 0; i < lines; i++)
    {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }    

    for (j = 0; j < lines; j++)  
    {
        for (i = 0; i < columns; i++)
        {
           /* scanf("%d", &matrix[i][j]);  printf(" \t"); */
            matrix[j][i] = 0;
        }
    }
    assert(Check(0, 0, squareSize, matrix) == 1);
    return 0;
}

#undef main
int main()
{
    Tests();
    printf("program has tasted");

    return 0;
}
