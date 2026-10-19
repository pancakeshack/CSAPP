#include <stdio.h>

int compare(int x, int y)
{
    int applied = x ^ y;
    return !applied;
}

int main(void)
{
    int t = compare(4, 4);
    int f = compare(1, 4);

    printf("%d\n", t);
    printf("%d\n", f);

    return 0;
}