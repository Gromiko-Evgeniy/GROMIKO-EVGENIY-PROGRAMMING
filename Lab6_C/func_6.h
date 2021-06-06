struct TreeElement
{
    struct TreeElement* right;
    struct TreeElement* left;
    char letter;
};

struct Tree
{
    struct TreeElement* root;
    int amount;
};


void CheckInput(char* arr);
int AddItemToTree(struct TreeElement** root, char ch, int* count);
int DeleteTreeItems(struct TreeElement** root, int* count);
void OutputTreeElements(struct TreeElement* root);
int Task(struct TreeElement* root, int *count);