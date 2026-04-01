#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "problema1.h"

void initializere(int n)
{
    a=(int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++) a[i]=rand()% 10000;
    printf("Tabloul a fost initializat cu %d elemente aleatorii\n", n);
}

void citire(int n)
{
    printf("\n");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
}

void eliberare()
{
     free(a);
     a=NULL;
     printf("\nMemoria a fost eliberata\n");
}

void bubble_sort(int n)
{
    clock_t start=clock();
    int i, j, x, y;
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
            if(a[j]>a[j+1])
        {
            x=a[j];
            a[j]=a[j+1];
            a[j+1]=x;
        }
    clock_t end=clock();
    double t=end-start;
    printf("Timp necesar pentru bubble sort (%d elemente): %lf", n, t/CLOCKS_PER_SEC);
    printf("\nVrei sa afisezi tabloul dupa soratre(1/0): ");
    scanf("%d", &y);
    if(y==1) citire(n);
}

void quick_sort(int p, int u)
{
    clock_t start=clock();
    if(p>=u) return;
    int x;
    int pivot=a[(p+u)/2];
    int i=p;
    int j=u;
    while(i<=j)
    {
        while(a[i]<pivot) i++;
        while(a[j]>pivot) j--;
        if(i<=j)
        {
            x=a[i];
            a[i]=a[j];
            a[j]=x;
            i++;
            j--;
        }
    }
    quick_sort(p,j);
    quick_sort(i,u);
}

void quick_sort_timp(int p, int u, int n)
{
    int y;
    clock_t start=clock();
    quick_sort(p, u);
    clock_t end=clock();
    double t=end-start;
    printf("Timp necesar pentru quick sort (%d elemente): %lf", n,  t/CLOCKS_PER_SEC);
    printf("\nVrei sa afisezi tabloul dupa soratre(1/0): ");
    scanf("%d", &y);
    if(y==1) citire(n);

}
