#include <math.h>

double fabs(double x)
{
    __asm__ ("fabs": "+t"(x));
    return x;
}

float fabsf(float x)
{
    __asm__ ("fabs": "+t"(x));
    return x;
}

long double fabsl(long double x)
{
    __asm__ ("fabs": "+t"(x));
    return x;
}
