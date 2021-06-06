#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "func_6.h"


int main(void)
{
    char str[15];
    int i = 0, count = 0;

    CheckInput(str);

    struct Tree TreeWithLetters = {NULL, 0};

    while(str[i] != '\n')
    {
        TreeWithLetters.amount = AddItemToTree(&TreeWithLetters.root, str[i], &TreeWithLetters.amount);
        i++;
    }

    OutputTreeElements(TreeWithLetters.root);

    printf("\nTask: %d", Task(TreeWithLetters.root, &count));

    DeleteTreeItems(&TreeWithLetters.root, &TreeWithLetters.amount);

    _getch();
    return 0;
}

void CheckInput(char* arr)
{
    int check = 0, i, count = 0;

    printf("Enter your word:\n");
    fgets(arr, 15, stdin);

    while(check == 0)
    {
        check = 1;
        for(i = 0; arr[i]; i++)
        {
            if(arr[0] == '\n' || (arr[i] < 'a' && arr[i] != '\n') || (arr[i] > 'z' && arr[i] != '\n'))
            {
                printf("Error input. Try again\n");
                check = 0;
                fgets(arr, 15, stdin);
                break;
            }
        }
    }
}

int AddItemToTree(struct TreeElement** root, char ch, int* count)
{
    struct TreeElement* newElement = (struct TreeElement*)malloc(sizeof(struct TreeElement));
    if(newElement == NULL)
    {
        return -1;
    }

    newElement->letter = ch;
    newElement->right = NULL;
    newElement->left = NULL;

    if((*root) == NULL)
    {
        (*root) = newElement;
        (*count)++;
    } else
    {
        if(ch < (*root)->letter)
        {
            return AddItemToTree(&(*root)->left, ch, count);
        } else if(ch > (*root)->letter)
        {
            return AddItemToTree(&(*root)->right, ch, count);
        } else
        {
            printf("Such letter already exists\n");
        }
    }

    return (*count);
}

int DeleteTreeItems(struct TreeElement** root, int* count)
{
    if((*root))
    {
        if((*root)->left) 
        {
            DeleteTreeItems(&(*root)->left, count);
        }
        if((*root)->right) 
        {
            DeleteTreeItems(&(*root)->right, count);
        }

        free((*root));
        (*root) = NULL;

        (*count)--;
    }

    return (*count);
}

void OutputTreeElements(struct TreeElement* root)
{
    if(root)
    {
        if(root->left) 
        {
            OutputTreeElements(root->left);
        }
        if(root->right) 
        {
            OutputTreeElements(root->right);
        }
        printf("%c ", root->letter);
    }
}

int Task(struct TreeElement* root, int *count)
{
    if(!root) return -1;

	if(root->right && root->right)
	{
		(*count)++;
	}

	Task(root->left, count);

	Task(root->right, count);

	return (*count);
}
