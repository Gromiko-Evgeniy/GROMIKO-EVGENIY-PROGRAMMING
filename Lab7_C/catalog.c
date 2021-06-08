#include "catalog.h"


int NumberOfLinesInFile(FILE *fl)
{
    char buffer[20];
    int number = 0;

    while(fgets(buffer, 20, fl) != NULL)
    {
        number++;
    }

    rewind(fl);
    return number;
}

int StrToInt(char* str)
{
    int lenght = 0, number = 0, k;

    while(str[lenght] != '\n')
    {
        lenght++;
    }

    for (lenght = lenght-1, k = 0; lenght >= 0; lenght--, k++)
    {
        number += (str[lenght] - '0') * pow(10,k);
    }

    return number;
}
 

int FillCatalog(struct Catalog* CatalogOfShop)
{
    FILE* database;
    int numberOfProducts, i = 0;
    char sectionFromFile[15];
    char nameFromFile[20];
    unsigned int priceFromFile;
    char presenceFromFile;
    char descriptionFromFile[20];
    unsigned int guaranteeFromFile;
    char countryFromFile[15];
    char temp[5];
    char* ch;


    database = fopen("database.txt", "r");
    if(database == NULL)
    {
        printf("file not found");
        return -1;
    }

    numberOfProducts = NumberOfLinesInFile(database)/7;
    
    while(i < numberOfProducts)
    {   
        fgets(sectionFromFile, 20, database);
        fgets(nameFromFile, 20, database);
        fgets(temp, 5, database);
        priceFromFile = StrToInt(temp);
        fgets(temp, 5, database);
        presenceFromFile = temp[0];
        fgets(descriptionFromFile, 20, database);
        fgets(temp, 5, database);
        guaranteeFromFile = StrToInt(temp);
        fgets(countryFromFile, 15, database);
        AddProduct(CatalogOfShop, sectionFromFile, nameFromFile, priceFromFile, presenceFromFile, 
                   descriptionFromFile, guaranteeFromFile, countryFromFile);
        i++;
    }

    fclose(database);

    return CatalogOfShop->amount;
}

int AddProduct(struct Catalog* CatalogOfShop, char* section, char* name, unsigned int price, char presence, char* description, 
               unsigned int guarantee, char* country)
{
    int i = 0;
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    if(!newProduct)
    {
        return -1;
    }

    newProduct->number = CatalogOfShop->amount;

    while(section[i])
    {
        newProduct->section[i] = section[i];
        i++;
    }
    if(section[i-1] == '\n')
    {
        newProduct->section[i-1] = '\0';
    } else
    {
        newProduct->section[i] = '\0';
    }
    i = 0;

    while(name[i])
    {
        newProduct->name[i] = name[i];
        i++;
    }
    if(name[i-1] == '\n')
    {
        newProduct->name[i-1] = '\0';
    } else
    {
        newProduct->name[i] = '\0';
    }
    i = 0;

    newProduct->price = price;

    newProduct->presence = presence;

    while(description[i])
    {
        newProduct->description[i] = description[i];
        i++;
    }
    if(description[i-1] == '\n')
    {
        newProduct->description[i-1] = '\0';
    } else
    {
        newProduct->description[i] = '\0';
    }
    i = 0;

    newProduct->guarantee = guarantee;

    while(country[i])
    {
        newProduct->country[i] = country[i];
        i++;
    }
    if(country[i-1] == '\n')
    {
        newProduct->country[i-1] = '\0';
    } else
    {
        newProduct->country[i] = '\0';
    }

    if(!(CatalogOfShop->head))
    {
        CatalogOfShop->head = newProduct;
        (CatalogOfShop->head)->next = NULL;
        (CatalogOfShop->head)->prev = NULL;
        CatalogOfShop->tail = CatalogOfShop->head;
    } else
    {
        struct Product* tempTail;

        tempTail = CatalogOfShop->tail;
        tempTail->next = newProduct;
        CatalogOfShop->tail = newProduct;
        (CatalogOfShop->tail)->prev = tempTail;
        (CatalogOfShop->tail)->next = NULL;
    }

    (CatalogOfShop->amount)++;

    return (CatalogOfShop->amount);
}

void OutputProduct(struct Product* Product)
{
    printf("Name: %s\n", Product->name);
    printf("Price: %d $\n", Product->price);
    printf("Description: %s\n", Product->description);
    printf("Guarantee: %d mounth\n", Product->guarantee);
    printf("Manufacturer: %s\n", Product->country);
    if(Product->presence == 'n')
    {
        printf("                       Not in stock");
    }
}

int OutputProducts(struct Catalog* CatalogOfShop, char section)
{
    struct Product* temp = CatalogOfShop->head;
    int count = 0;

    while(temp)
    {
        if(temp->section[0] == section)
        {
            OutputProduct(temp);

            count++;

            printf("\n\n");
        }

        temp = temp->next;
    }

    return count;
}

void AllProductsOutput(struct Catalog* CatalogOfShop)
{
    struct Product* temp = CatalogOfShop->head;

    while(temp)
    {
        OutputProduct(temp);

        printf("\n\n");

        temp = temp->next;
    }
}

int SearchName(struct Catalog* CatalogOfShop, char* name)
{
    struct Product* temp = CatalogOfShop->head;
    int find = 0;

    while(temp)
    {
        if(temp->name[0] == name[0] && temp->name[1] == name[1] && temp->name[2] == name[2])
        {
            OutputProduct(temp);

            printf("\n\n");

            find++;
        }
        temp = temp->next;
    }

    if(find == 0)
    {
        printf("                                     Nothing found\n");
    }

    return find;
}

int SearchDescription(struct Catalog* CatalogOfShop, char* description)
{
    struct Product* temp = CatalogOfShop->head;
    int find = 0;

    while(temp)
    {
        if(temp->description[0] == description[0] && temp->description[1] == description[1] && temp->description[2] == description[2])
        {
            OutputProduct(temp);

            printf("\n\n");
            find++;
        }

        temp = temp->next;
    }

    if(find == 0)
    {
        printf("                                     Nothing found\n");
    }

    return find;
}

int AddToGarbage(struct Garbage* UserGarbage, struct Product* Product)
{
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    int i = 0;

    newProduct->number = Product->number;

    while(Product->section[i])
    {
        newProduct->section[i] = Product->section[i];
        i++;
    }
    newProduct->section[i] = '\0';
    i = 0;

    while(Product->name[i])
    {
        newProduct->name[i] = Product->name[i];
        i++;
    }
    newProduct->name[i] = '\0';
    i = 0;

    newProduct->price = Product->price;

    newProduct->presence = Product->presence;

    while(Product->description[i])
    {
        newProduct->description[i] = Product->description[i];
        i++;
    }
    newProduct->description[i] = '\0';
    i = 0;

    newProduct->guarantee = Product->guarantee;

    while(Product->country[i])
    {
        newProduct->country[i] = Product->country[i];
        i++;
    }
    newProduct->country[i] = '\0';

    if(!(UserGarbage->head))
    {
        UserGarbage->head = newProduct;
        (UserGarbage->head)->next = NULL;
        (UserGarbage->head)->prev = NULL;
        UserGarbage->tail = UserGarbage->head;
    } else
    {
        struct Product* tempTail;

        tempTail = UserGarbage->tail;
        tempTail->next = newProduct;
        UserGarbage->tail = newProduct;
        (UserGarbage->tail)->prev = tempTail;
        (UserGarbage->tail)->next = NULL;
    }

    (UserGarbage->amount)++;
    UserGarbage->sum += newProduct->price;

    return (UserGarbage->amount);
}

int DeleteCatalog(struct Catalog* CatalogOfShop)
{
    struct Product* temp;

    while(CatalogOfShop->head)
    {
        temp = CatalogOfShop->head;
        CatalogOfShop->head = (CatalogOfShop->head)->next;

        free(temp);
        (CatalogOfShop->amount)--;
    }

    return (CatalogOfShop->amount);
}

int DeleteGarbage(struct Garbage* MyGarbage)
{
    struct Product* temp;

    while(MyGarbage->head)
    {
        temp = MyGarbage->head;
        MyGarbage->head = (MyGarbage->head)->next;

        MyGarbage->sum -= temp->price;
        free(temp);
        (MyGarbage->amount)--;
    }

    return (MyGarbage->amount);
}

int DeleteReport(struct List* Report)
{
    struct Customer* temp;

    while(Report->head)
    {
        temp = Report->head;
        Report->head = (Report->head)->next;

        Report->amount -= temp->products->amount;
        DeleteCatalog(temp->products);

        free(temp);
    }

    return (Report->amount);
}

int AddCustomer(struct List* MyList, struct Garbage* cosmetics, char* name, char* surname)
{
    int i = 0;
    struct Product* temp = cosmetics->head;

    struct Catalog* cat = (struct Catalog*)malloc(sizeof(struct Catalog));
    if(!cat)
    {
        return -1;
    }

    struct Customer* newCustomer = (struct Customer*)malloc(sizeof(struct Customer));
    if(!newCustomer)
    {
        return -1;
    }

    cat->head = NULL;
    cat->tail = NULL;
    cat->amount = 0;

    while(temp)
    {
        AddProduct(cat, temp->section, temp->name, temp->price, temp->presence, temp->description, temp->guarantee, temp->country);
        (MyList->amount)++;
        MyList->sum += temp->price;
        temp = temp->next;
    }

    newCustomer->products = cat;

    while(name[i])
    {
        newCustomer->name[i] = name[i];
        i++;
    }
    newCustomer->name[i] = '\0';
    i = 0;

    while(surname[i])
    {
        newCustomer->surname[i] = surname[i];
        i++;
    }
    newCustomer->surname[i] = '\0';


    if(!(MyList->head))
    {
        MyList->head = newCustomer;
        (MyList->head)->next = NULL;
        (MyList->head)->prev = NULL;
        MyList->tail = MyList->head;
    } else
    {
        struct Customer* tempTail;

        tempTail = MyList->tail;
        tempTail->next = newCustomer;
        MyList->tail = newCustomer;
        (MyList->tail)->prev = tempTail;
        (MyList->tail)->next = NULL;
    }

    return (MyList->amount);
}

void OutputReport(struct List* MyList)
{
    FILE* report;
    struct Customer* temp = MyList->head;

    report = fopen("report.txt", "w");
    if(report == NULL)
    {
        printf("file not found");
        return;
    }

    fprintf(report, "Revenue %d\n", MyList->sum);
    fprintf(report, "Number of items sold: %d\n", MyList->amount);

    printf("SALED:\n\n");

    while(temp)
    {
        fprintf(report, "%s %s\n", temp->name, temp->surname);
        printf("To whom: %s %s\n", temp->name, temp->surname);
        AllProductsOutput(temp->products);

        temp = temp->next;
    }

    printf("Result:\n");
    printf("Number of items sold: %d\t Revenue: %d $\n", MyList->amount, MyList->sum);

    fclose(report);

}