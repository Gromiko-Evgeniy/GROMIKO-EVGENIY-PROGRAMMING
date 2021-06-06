#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "func_6.h" 


int Test(void)
{
    struct Tree TreeWithLetters = {NULL, 0};
    int count = 0;

    assert(AddItemToTree(&TreeWithLetters.root, 'h', &TreeWithLetters.amount) == 1);
    assert(TreeWithLetters.root != NULL);
    assert(AddItemToTree(&TreeWithLetters.root, 'e', &TreeWithLetters.amount) == 2);
    assert(AddItemToTree(&TreeWithLetters.root, 'l', &TreeWithLetters.amount) == 3);
    assert(AddItemToTree(&TreeWithLetters.root, 'l', &TreeWithLetters.amount) == 3);

    assert(Task(TreeWithLetters.root, &count) == 1);

    assert(DeleteTreeItems(&TreeWithLetters.root, &TreeWithLetters.amount) == 0);

    return 0;
}

#undef main
int main(void)
{
    Test();

    printf("Test passed successfully");

    return 0;
} 
