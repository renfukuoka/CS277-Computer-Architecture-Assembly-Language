#include <stdio.h>
#include <math.h>

int main()
{
    long long i;
    for (i = 5; i <= 5000000; i *= 10)
    {
        printf("%10lld %lld\n", i, i * i);
    }
    return 0;
}