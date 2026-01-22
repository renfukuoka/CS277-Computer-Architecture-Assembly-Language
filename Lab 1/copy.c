#include <stdio.h>
#include <time.h>

static int a[2048][2048];
static int b[2048][2048];
static int c[2048][2048];
static int d[2048][2048];

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
    copy(a, b);
    delta = time_get() - before;

    unsigned long before2, delta2;

    before2 = time_get();
    copy(c, d);
    delta2 = time_get() - before2;

    printf("copy time: %lu ns\ncopy2 time: %lu ns", delta, delta2);
    return 0;
}
