#include <stdio.h>

int main()
{
    char c = 'a';
    char *p = 0;
    p += 48;
    printf("%p\n", p);
    int i = 314;
    int *q = 0;
    printf("%p\n", q);
    q += 1; // q[1]
    printf("%p\n", q);
    q += 1; // q[2]
    printf("%p\n", q);
}