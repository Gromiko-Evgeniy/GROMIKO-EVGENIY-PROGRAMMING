#include "catalog.h"

int CheckYourChoise(char* arr, char a, char b);
void UserInterface(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers); 
void SectionSelection(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers); /*  1.2 функции вывода списка  */
void Search(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers);  /* поисковик  */
void InGarbage(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers);
void Garbage(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers); /* корзина */
void Checkout(struct Garbage* UserGarbage, struct List* Customers, struct Catalog* Shop);
void ToSeeReport(struct Catalog* Shop, struct Garbage* UserGarbage, struct List* Customers); /*  отчет о проданных товарах   */