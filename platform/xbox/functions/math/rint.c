#include <math.h>
#include <assert.h>

double rint(double x)
{
    __asm__ ("frndint;"
             : "=t"(x) : "0"(x));
    return x;
}

float rintf(float x)
{
    __asm__ ("frndint;"
             : "=t"(x) : "0"(x));
    return x;
}

long double rintl(long double x)
{
    __asm__ ("frndint;"
             : "=t"(x) : "0"(x));
    return x;
}
