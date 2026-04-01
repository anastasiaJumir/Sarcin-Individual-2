#include <stdio.h>
#include <stdlib.h>
#include "problema1.c"


int main()
{
    int n=0, x;
    do
    {
        printf("\n\tMeniu\n");
        printf("1. Initializarea tabloului cu numere aleatorii\n");
        printf("2. Afisarea tabloului\n");
        printf("3. Eliberarea memoriei tabloului\n");
        printf("4. Sortarea tablolui utilizand bubble sort\n");
        printf("5. Sortarea tabloului utilizand quick sort\n");
        printf("0. Esirea din program\n");
        printf("\nAlege optiunea: ");
        scanf("%d", &x);

        switch(x)
        {
        case 1:
            {
                 printf("\nIntroduceti numarul de elemente: ");
                 scanf("%d", &n);
                 initializere(n);
                 break;
            }
        case 2:
            citire(n);
            break;
        case 3:
            eliberare();
            break;
        case 4:
            bubble_sort(n);
            break;
        case 5:
            quick_sort_timp(0, n-1, n);
            break;
        }
    }
    while(x!=0);
    return 0;
}
