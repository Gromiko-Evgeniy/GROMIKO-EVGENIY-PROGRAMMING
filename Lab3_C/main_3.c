#include <stdio.h>
#include <stdlib.h>
#include "Lab3_C_header.h"

int main()
{   
    int columns, lines;
    int squareSize;
    int i, j, temp1, temp2;

    /* -------------------------------------------------------------------------------- */
    /*  */
    int a = 1;
    while (a == 1)
	{
        temp2 = 0;
		printf("Enter matrix size \n");
        printf("number of columns: "); scanf("%d", &columns);
        if (columns>0 && columns<20)
        {
            printf("Well done) \n"); 
        }else
        {
            printf("Wrong imput. Try again \n");
            continue;
        }
         
        printf("number of lines: "); scanf("%d", &lines);
        if (lines>0 && lines<20)
        {
            printf("Well done) \n"); 
        }else
        {
            printf("Wrong imput. Try again \n");
            continue;
        }

        printf("\nEnter square size: "); scanf("%d", &squareSize);
        if (squareSize<=columns && squareSize<=lines)
        {
            printf("Well done) \n"); 
        }else
        {
            printf("Wrong imput. Try again \n");
            continue;
        }

        printf("Enter your matrix \n");

        /* -------------------------------------------------------------------------------- */

        int **matrix = (int**)malloc(lines * sizeof(int*));
        for(i = 0; i < lines; i++)
        {
            matrix[i] = (int *)malloc(columns * sizeof(int));
        }

        /* -------------------------------------------------------------------------------- */


        for (j = 0; j < lines; j++)  
        {
            for (i = 0; i < columns; i++)
            {
               /* scanf("%d", &matrix[i][j]);  printf(" \t"); */
                /*matrix[j][i] = getche();*/
		scanf ("%d", &matrix[j][i]);    
                printf("\t");
            }
            printf(" \n");
        }

        /* -------------------------------------------------------------------------------- */


        for (j = 0; j < lines - squareSize+1; j++)  
        {
            temp1 = 0;
            for (i = 0; i < columns - squareSize+1; i++)
            {   
                if(Check(j, i, squareSize, matrix) == 1)
                {
                    printf("Found ");
                    temp1 = 1;
                    break;
                }
            }
            if (temp1 == 1)
            {
                break;
            }
        }
        /*free();*/
        break;
	}
    return 0;
} 

int Check(int _lineNum, int _colNum, int _squareSize, int **matrix)
{
    int i, j, temp = 0;
    for (i = 0; i < _squareSize; i++)
    {
        for (j = 0; j < _squareSize-1; j++)
        {
           if(matrix[_lineNum+i][_colNum+j] == matrix[_lineNum+i][_colNum+1+j]) 
           {
                temp++;
                /* printf(")))))))))))))))))))))))))))))))\n"); */
           }
           else
           {
               temp = 0;
               break;
           }
        }
        if (temp == 0)
        {
           return 0;
        }
        
    }
    if (temp + _squareSize == _squareSize*_squareSize)
    {
        return 1;
    }
}

