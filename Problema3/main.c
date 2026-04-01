#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int *digits;
    int length;
} BigInt;

void add(BigInt *A, BigInt *B, BigInt *R)
{
    int carry = 0;
    int max_len = A->length > B->length ? A->length : B->length;
    for (int i = 0; i < max_len || carry; i++)
    {
        int sum = carry + (i < A->length ? A->digits[i] : 0) + (i < B->length ? B->digits[i] : 0);
        R->digits[i] = sum % 10;
        carry = sum / 10;
        if (i >= R->length) R->length++;
    }
}

void fibonacci(int n)
{
    if (n == 0)
    {
        printf("0\n");
        return;
    }
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    int max_digits = (int)(n * 0.21) + 10;// Estimare spatiu
    BigInt a = {(int*)calloc(max_digits, sizeof(int)), 1};
    BigInt b = {(int*)calloc(max_digits, sizeof(int)), 1};
    BigInt res = {(int*)calloc(max_digits, sizeof(int)), 1};
    a.digits[0] = 0;
    b.digits[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        res.length = 0;
        add(&a, &b, &res);
        memcpy(a.digits, b.digits, b.length * sizeof(int));
        a.length = b.length;
        memcpy(b.digits, res.digits, res.length * sizeof(int));
        b.length = res.length;
    }
    if (n <= 500)
    {
        for (int i = b.length - 1; i >= 0; i--) printf("%d", b.digits[i]);
        printf("\n");
    }
    else printf("Fib(%d) calculat cu succes (%d cifre).\n", n, b.length);
    free(a.digits);
    free(b.digits);
    free(res.digits);
}

int main()
{
    int n;
    double t;
    printf("Intrudu pozitia elementului: ");
    scanf("%d",&n);
    clock_t start=clock();
    fibonacci(n);
    clock_t end=clock();
    t=end-start;
    printf("Timp necesar: %lf", t/CLOCKS_PER_SEC);
    return 0;
}

