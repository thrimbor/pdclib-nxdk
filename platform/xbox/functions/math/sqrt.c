#include <math.h>

double sqrt(double x)
{
    __asm__ ("fsqrt" : "+t"(x));
    return x;
}

float sqrtf(float x)
{
    __asm__ ("fsqrt" : "+t"(x));
    return x;
}

long double sqrtl(long double x)
{
    __asm__ ("fsqrt" : "+t"(x));
    return x;
}
