#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Product
{
    unsigned int number;
    char section[15];
    char name[20];
    unsigned int price;
    char presence;
    char description[20];
    unsigned int guarantee;
    char country[15];
    struct Product* next;
    struct Product* prev;
};

struct Catalog
{ 
    struct Product* head;
    struct Product* tail;
    int amount;
};

struct Garbage
{
    struct Product* head;
    struct Product* tail;
    int amount;
    int sum;
}; 

struct Customer
{
    char surname[15];
    char name[15];
    struct Catalog* products;
    struct Customer* prev;
    struct Customer* next;
};

struct List
{
    struct Customer* head;
    struct Customer* tail;
    int amount;

    int sum;
};

int NumberOfLinesInFile(FILE *fl);
int StrToInt(char* str); 
int AddProduct(struct Catalog* CatalogOfShop, char* section, char* name, unsigned int price, char presence, char* description, unsigned int guarantee, char* country);
int FillCatalog(struct Catalog* CatalogOfShop); 
void OutputProduct(struct Product* Product);
int OutputProducts(struct Catalog* CatalogOfShop, char section);
void AllProductsOutput(struct Catalog* CatalogOfShop);
int SearchName(struct Catalog* CatalogOfShop, char* name);
int SearchDescription(struct Catalog* CatalogOfShop, char* description);
int AddToGarbage(struct Garbage* UserGarbage, struct Product* product);
int DeleteCatalog(struct Catalog* CatalogOfShop);
int DeleteGarbage(struct Garbage* MyGarbage);
int DeleteReport(struct List* Report);
int AddCustomer(struct List* MyList, struct Garbage* cosmetics, char* name, char* surname);
void OutputReport(struct List* MyList);
