#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first <= last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}

void print_array(int a[], int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int challenge_a(int a)
{
    int mask = 0b11111111;
    return a & mask;
}

int challenge_b(int a)
{
    int initial_mask = 0b11111111;
    int lowest_byte = a & initial_mask;
    int inverted = ~a;
    int clear_mask = 0b00000000;
    inverted = inverted & ~initial_mask;
    return inverted | lowest_byte;
}

int challenge_c(int a)
{
    int mask = 0b11111111;
    return a | mask;
}

int main(void)
{
    int x = 0x87654321;

    printf("0x%08x\n", challenge_a(x));
    printf("0x%08x\n", challenge_b(x));
    printf("0x%08x\n", challenge_c(x));

    return 0;
}