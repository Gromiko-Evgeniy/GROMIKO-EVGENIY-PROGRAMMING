#include "func_7.h"


int main(void)
{
    struct Catalog Shop = {NULL, NULL, 0};
    struct Garbage UserGarbage = {NULL, NULL, 0 , 0};
    struct List Customers = {NULL, NULL, 0, 0};


    FillCatalog(&Shop);

    UserInterface(&Shop, &UserGarbage, &Customers);

    DeleteCatalog(&Shop);
    DeleteReport(&Customers);

    return 0;
}

int CheckYourChoise(char* arr, char a, char b)
{
    int check = 0;

    scanf("%15s", arr);

    while(check == 0)
    {
        check = 1;
        if((arr[0] != a && arr[0] != b && arr[0] != 'b') || arr[1])
        {
            if(arr[0] == 'r' && arr[1] == 'e' && arr[2] == 'p')
            {
                break;
            }
            printf("Error input. Try again\n");
            check = 0;
            scanf("%15s", arr);
        }
    }

    return check;
}

void UserInterface(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    char choise[15];



    printf("                                                    WELCOME                       \n");

    printf("                                                                         Hint: If you want to go out press 'b'\n");
    printf("Want to see a catalog or search for a specific product?\n\n");

    printf("1.To see a catalog\n");
    printf("2.To search for a specific product\n");

    CheckYourChoise(choise, '1', '2');
    if(choise[0] != 'b')
    {
        system("cls");

        if(choise[0] == '1')
        {
            SectionSelection(Shop, UserGarbage, Customers);
        } else if(choise[0] == '2')
        {
            Search(Shop, UserGarbage, Customers);
        } else
        {
            return ToSeeReport(Shop, UserGarbage, Customers);
        }
        
        InGarbage(Shop, UserGarbage, Customers);
    }

    system("cls");
}

void SectionSelection(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    char choise[15];



    printf("                                                                         Hint: If you want to go out press 'b'\n");

    printf("1.Decorative cosmetics\n");
    printf("2.Care cosmetics\n");
    CheckYourChoise(choise, '1', '2');

    system("cls");

    if(choise[0] == '1')
    {
        OutputProducts(Shop, 'd');
    } else if(choise[0] == '2')
    {
        OutputProducts(Shop, 'c');
    } else
    {
        UserInterface(Shop, UserGarbage, Customers);
    }
}

void Search(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    char choise[15];
    char search[15];

    printf("                                                            If you want to go back press 'b'\n");

    printf("Want to search for a product by name or description? n/d\n");
    CheckYourChoise(choise, 'n', 'd');

    system("cls");

    if(choise[0] == 'n')
    {
        printf("                                                            If you want to go back press 'b'\n");

        printf("Enter name:\n");
        scanf("%s", search);

        system("cls");

        if(search[0] == 'b')
        {
            return Search(Shop, UserGarbage, Customers);
        } 

        SearchName(Shop, search);
    } else if(choise[0] == 'd')
    {
        printf("                                                            If you want to go back press 'b'\n");

        printf("Enter description:\n");
        scanf("%s", search);

        if(search[0] == 'b')
        {
            system("cls");
            return Search(Shop, UserGarbage, Customers);
        }
        SearchDescription(Shop, search);
    } else
    {
        return UserInterface(Shop, UserGarbage, Customers);
    }
}

void InGarbage(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    struct Product* temp = Shop->head;
    char name[15];
    int amount = 0;

    printf("                                                            If you want to go back press 'b'\n");

    printf("What do you want to buy? Enter name:\n");
    scanf("%s", name);

    if(name[0] == 'b')
    {
        system("cls");
        UserInterface(Shop, UserGarbage, Customers);
    } else
    {
        while(temp)
        {
            if(temp->name[0] == name[0] && temp->name[1] == name[1] && temp->name[2] == name[2])
            {
                if(temp->presence == 'n')
                {
                    printf("Product is out of stock\n");
                    return InGarbage(Shop, UserGarbage, Customers);
                }
                AddToGarbage(UserGarbage, temp);
                amount++;
            }
            temp = temp->next;
        }
    }

    if(amount == 0)
    {
        printf("                                     Nothing found\n");

        return InGarbage(Shop, UserGarbage, Customers);
    }

    printf("Product added to cart\nDo you want go to cart? y/n\n");
    CheckYourChoise(name, 'y', 'n');

    system("cls");

    if(name[0] == 'y')
    {
        Garbage(Shop, UserGarbage, Customers);
    } else
    {
        UserInterface(Shop, UserGarbage, Customers);
    }
}

void Garbage(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    struct Product* temp = UserGarbage->head;
    char choise[15];

    printf("                                                            If you want to go back press 'b'\n");

    printf("Your orders:\n");
    while(temp)
    {
        OutputProduct(temp);

        temp = temp->next;

        printf("\n\n");
    }
    printf("                           The number of your orders: %d\n", UserGarbage->amount);
    printf("                           Total amount of money: %d\n", UserGarbage->sum);

    printf("Want to place an order? y/n\n");
    CheckYourChoise(choise, 'y', 'n');

    system("cls");

    if(choise[0] == 'y')
    {
        Checkout(UserGarbage, Customers, Shop);
    } else
    {
        UserInterface(Shop, UserGarbage, Customers);
    }

}

void Checkout(struct Garbage* UserGarbage, struct List* Customers, struct Catalog* Shop)
{
    char name[15];
    char surname[15];
    char a;

    printf("Enter your name: ");
    scanf("%15s", name);

    printf("Enter your surname: ");
    scanf("%15s", surname);

    AddCustomer(Customers, UserGarbage, name, surname);

    printf("Order is processed. Press any key");
    scanf(" %c", &a);

    DeleteGarbage(UserGarbage);

    system("cls");

    UserInterface(Shop, UserGarbage, Customers);
}

void ToSeeReport(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers)
{
    char password[10];
    int check = 0;
    char a;
    printf("Enter password:\n");
    
    scanf("%s", password);

    while(check == 0)
    {
        check = 1;
        if(password[0] != 'l' || password[1] != 'a' || password[2] != 'b')
        {
            printf("Access error. Enter password:\n");
            scanf(" %s", password);
            check = 0;
        } else if(password[0] == 'b' && password[1] == '\n')
        {
            UserInterface(Shop, UserGarbage, Customers);
        }
    }

    system("cls");

    OutputReport(Customers);

    printf("                                          Press any key\n");

    scanf(" %c", &a);

    system("cls");

    UserInterface(Shop, UserGarbage, Customers);
}