#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "func_5.h"

int Test()
{
    char arr[15];
    struct List MyList = {NULL, NULL, 0};
    struct Stack MyStack = {NULL, 0};

    assert(CheckYourChoise(arr) == 1);

    assert(CheckInput(arr) == 1);

    assert(AddItemToList(&MyList, arr) == 1);
    assert(MyList.head != NULL);
    assert(AddItemToList(&MyList, arr) == 2);

    assert(DeleteList(&MyList) == 0);
    assert(MyList.head == NULL);

    assert(AddItemToStack(&MyStack) == 1);
    assert(MyStack.head != NULL);
    
    assert(ExtractItemFromStack(&MyStack) == 0);
    assert(MyStack.head == NULL);

    return 0;
}

#undef main
int main()
{
    Test();

    printf("\nTest passed successfully");

    return 0;
}
