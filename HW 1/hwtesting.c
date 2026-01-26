#include <stdio.h>
#include <math.h>

int main()
{
#define SQUAREOF(x) (x) * (x)

    printf("%d\n", SQUAREOF(2 + 2));

    return 0;
}