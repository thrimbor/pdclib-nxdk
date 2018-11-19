#include <math.h>

double sin(double x)
{
    __asm__ ("fsin" : "+t" (x));
    return x;
}

float sinf(float x)
{
    __asm__ ("fsin" : "+t" (x));
    return x;
}

long double sinl(long double x)
{
    __asm__ ("fsin" : "+t" (x));
    return x;
}
