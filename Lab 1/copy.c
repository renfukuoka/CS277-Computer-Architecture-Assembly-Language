#include <stdio.h>
#include <time.h>

void copy(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for (i = 0; i < 2048; i++)
    {
        for (j = 0; j < 2048; j++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

void copy2(int src[2048][2048], int dst[2048][2048])
{
    int i, j;
    for (j = 0; j < 2048; j++)
    {
        for (i = 0; i < 2048; i++)
        {
            dst[i][j] = src[i][j];
        }
    }
}

const unsigned long billion = 1000000000ULL;
/**
 * Return the current time in nanoseconds.
 */
unsigned long time_get()
{
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);
    return billion * t.tv_sec + t.tv_nsec;
}

int main()
{
    unsigned long before, delta;

    before = time_get();
    copy();
    delta = time_get() - before;
}
