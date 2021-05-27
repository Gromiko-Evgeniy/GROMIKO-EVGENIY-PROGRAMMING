#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "func_5.h"


int main(void)
{
    char ch[10];
    struct Stack StackWithLists = {NULL, 0};

    do
    {
        AddItemToStack(&StackWithLists);
  
        printf("Do you want to add a new item to stack?\n"); 
        CheckYourChoise(ch);
    } while (ch[0] == 'y');

    while(ExtractItemFromStack(&StackWithLists) != 0)
    {}

    _getch();
    return 0;
}

int CheckYourChoise(char* arr)
{
    int check = 0;

    fgets(arr, 15, stdin);

    while(check == 0)
    {
        check = 1;
        if((arr[0] != 'y' && arr[0] != 'n') || arr[1] != '\n')
        {
            printf("Error input. Try again\n");
            check = 0;
            fgets(arr, 15, stdin);
        }
    }

    return check;
}

int CheckInput(char* arr)
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

    return check;
}

int AddItemToList(struct List* MyList, char* word)
{
    int i;

    CheckInput(word);

    struct ListElement* newElement = (struct ListElement*) malloc(sizeof(struct ListElement));
    if(newElement == NULL)
    {
        return -1;
    }
    
    for(i = 0; word[i]; i++)
    {
        newElement->word[i] = word[i];
    }
    newElement->word[i] = '\0';

    if(!(MyList->head))
    {
        MyList->head = newElement;
        (MyList->head)->next = NULL;
        (MyList->head)->prev = NULL;
        MyList->tail = MyList->head;
    } else
    {
        struct ListElement* tempTail;

        tempTail = MyList->tail;
        tempTail->next = newElement;
        MyList->tail = newElement;
        (MyList->tail)->prev = tempTail;
        (MyList->tail)->next = NULL;
    }

    (MyList->amount)++;

    return (MyList->amount);
}

int DeleteList(struct List* MyList)
{
    struct ListElement* temp;

    while(MyList->head)
    {
        temp = MyList->head;
        MyList->head = (MyList->head)->next;

        free(temp);
        (MyList->amount)--;
    }

    return (MyList->amount);
}

int AddItemToStack(struct Stack* MyStack)
{
    char choise[15];
    char word[15];

    struct List* ListWithWords = (struct List*)malloc(sizeof(struct List));
    if(ListWithWords == NULL)
    {
        return -1;
    }

    ListWithWords->head = NULL;
    ListWithWords->tail = NULL;
    ListWithWords->amount = 0;

    struct StackElement* newStackElement = (struct StackElement*)malloc(sizeof(struct StackElement));
    if(newStackElement == NULL)
    {
        return -1;
    }

    do
    {
        AddItemToList(ListWithWords, word);

        printf("Do you want to add a new word?\n"); 
        CheckYourChoise(choise);
    } while (choise[0] == 'y'); 

    newStackElement->ListInStack = ListWithWords;

    if(MyStack->head == NULL)
    {
        MyStack->head = newStackElement;
        (MyStack->head)->next = NULL;
    } else 
    {
        struct StackElement* temp;
        temp = MyStack->head;
        MyStack->head = newStackElement;
        (MyStack->head)->next = temp;
    }

    (MyStack->amount)++;

    return MyStack->amount; 
}

int ExtractItemFromStack(struct Stack* MyStack)
{
    struct List* ExtractList = (MyStack->head)->ListInStack;
    struct StackElement* temp = MyStack->head;

    MyStack->head = (MyStack->head)->next;

    WordOutput(ExtractList->head);
    DeleteList(ExtractList);

    free(temp);
    (MyStack->amount)--;

    return MyStack->amount;
}

void WordOutput(struct ListElement* Word)
{
    struct ListElement* temp;
    char word[15];
    int i = 0, position, k;

    temp = Word->next;

    while(Word->word[i])
    {
        i++;
    }
    position = i;

    for(k = 0; k < i; k++)
    {
        word[k] = Word->word[position-1];
        position--;
    }
    word[i] = '\0';

    printf("%s", word);

    if(temp != NULL)
    {
        WordOutput(temp);
    }
}
