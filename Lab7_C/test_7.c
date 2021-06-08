#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "func_7.h"

int Test(void)
{
    FILE* fl;
    char str[5] = "12\n";
    struct Catalog Shop = {NULL, NULL, 0};
    char section[5] = "care";
    char name[5] = "alya";
    char name1[5] = "eye";
    char presence = 'y';
    char description[7] = "pomade";
    char country[8] = "belarus";
    struct Garbage UserGarbage = {NULL, NULL, 0 , 0};
    struct List Customers = {NULL, NULL, 0, 0};

    fl = fopen("database.txt", "r+");
    if(fl == NULL)
    {
        printf("file not found");
        return -1;
    }

    assert(NumberOfLinesInFile(fl) == 42);
    
    fclose(fl);

    assert(FillCatalog(&Shop) == 6);

    assert(AddProduct(&Shop, section, name, 12, presence, description, 17, country) == 7);

    assert(AddToGarbage(&UserGarbage, Shop.head) == 1);

    assert(AddCustomer(&Customers, &UserGarbage, name, name) == 1);

    assert(OutputProducts(&Shop, 'c') == 4);

    printf("%d\n", OutputProducts(&Shop, 'c'));

    assert(SearchDescription(&Shop, name1) == 3);

    assert(SearchDescription(&Shop, name) == 0);

    assert(DeleteReport(&Customers) == 0);

    assert(DeleteCatalog(&Shop) == 0);

    assert(DeleteGarbage(&UserGarbage) == 0);

    return 0;
}

#undef main
int main(void)
{
    Test();

    printf("\nTest passed successfully");

    _getch();
    return 0;
}