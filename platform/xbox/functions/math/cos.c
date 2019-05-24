#include <math.h>

double cos(double x)
{
    __asm__ __volatile__ ("fcos" : "+t" (x));
    return x;
}

float cosf(float x)
{
    __asm__ __volatile__ ("fcos" : "+t" (x));
    return x;
}

long double cosl(long double x)
{
    __asm__ __volatile__ ("fcos" : "+t" (x));
    return x;
}
