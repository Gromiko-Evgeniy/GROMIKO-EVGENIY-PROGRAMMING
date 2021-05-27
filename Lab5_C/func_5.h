struct ListElement
{
    char word[15];
    struct ListElement* next;
    struct ListElement* prev;    
};

struct List
{
    struct ListElement* head;
    struct ListElement* tail; 
    int amount;   
};

struct StackElement
{
    struct List* ListInStack;
    struct StackElement* next;
};

struct Stack
{
    struct StackElement* head;
    int amount;
};


int CheckYourChoise(char* arr);
int CheckInput(char* arr);
int AddItemToList(struct List* MyList, char* word);
int DeleteList(struct List* MyList);
int AddItemToStack(struct Stack* MyStack);
void WordOutput(struct ListElement* Word);
int ExtractItemFromStack(struct Stack* MyStack);