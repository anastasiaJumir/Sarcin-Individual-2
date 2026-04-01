#include <stdio.h>
#include <stdlib.h>
#include "problema2.h"

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

void linear_search(int n, int x, int y)
{
    for(int i=0; i<n; i++)
        if(a[i]==x)
    {
        if (y==1) printf("Elementul %d a fost gasit pe pozitia %d\n", x, i);
        return;
    }
    if (y==1) printf("Elementul %d nu a fost gasit\n", x);
}

void sortare(int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i]>a[j])
            {
                int aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}

void binary_search(int n, int x, int y)
{
    int st=0, dr=n-1;
    while (st<=dr)
    {
        int mid=(st+dr)/2;
        if (a[mid]==x)
        {
            if (y==1) printf("Elementul %d a fost gasit pe pozitia %d\n", x, mid);
            return 0;
        }
        else if (a[mid]<x) st=mid+1;
        else dr=mid-1;
    }
    if (y==1) printf("Elementul %d nu a fost gasit\n", x);
}

