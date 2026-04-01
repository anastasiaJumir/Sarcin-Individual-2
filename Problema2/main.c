#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "problema2.c"

int main()
{
int n=0, x, y, m;
    do
    {
        printf("\n\tMeniu\n");
        printf("1. Initializarea tabloului cu numere aleatorii\n");
        printf("2. Afisarea tabloului\n");
        printf("3. Eliberarea memoriei tabloului\n");
        printf("4. Cautarea unui numar folosind linear search\n");
        printf("5. Cautarea unui numar folosind binary search\n");
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
            printf("\n1. Cautarea unui element introdus de la tastatura.\n");
            printf("2. Cautarea a unor 100000 aleatoare.\n");
            printf("Alege optiunea: ");
            scanf("%d", &y);
            if(y==1)
            {

                printf("Introduceti elementul cautat: ");
                scanf("%d", &m);
                clock_t start=clock();
                linear_search(n, m, y);
                clock_t end=clock();
                double t=end-start;
                printf("Timp pentru cautarea unui element(linear search): %lf\n", t/CLOCKS_PER_SEC);
            }
            if(y==2)
            {
                clock_t start=clock();
                for(int i=0; i<100000; i++)
                {
                    m=rand()% 10000;
                    linear_search(n, m, y);
                }
                 clock_t end=clock();
                 double t=end-start;
                 printf("Timp pentru cautarea a 100000 de elemente (linear search): %lf\n", t/CLOCKS_PER_SEC);

            }
            break;
        case 5:
            sortare(n);
            printf("\n1. Cautarea unui element introdus de la tastatura.\n");
            printf("2. Cautarea a unor 100000 aleatoare.\n");
            printf("Alege optiunea: ");
            scanf("%d", &y);
            if(y==1)
            {

                printf("Introduceti elementul cautat: ");
                scanf("%d", &m);
                clock_t start=clock();
                binary_search(n, m, y);
                clock_t end=clock();
                double t=end-start;
                printf("Timp pentru cautarea unui element(binary search): %lf\n", t/CLOCKS_PER_SEC);
            }
            if(y==2)
            {
                clock_t start=clock();
                for(int i=0; i<100000; i++)
                {
                    m=rand()% 10000;
                    binary_search(n, m, y);
                }
                 clock_t end=clock();
                 double t=end-start;
                 printf("Timp pentru cautarea a 100000 de elemente (binary search): %lf\n", t/CLOCKS_PER_SEC);

            }
            break;
        }
    }
    while(x!=0);
    return 0;
}
