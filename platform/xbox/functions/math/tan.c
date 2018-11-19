#include <math.h>

double tan(double x)
{
    __asm__ ("fptan;"
             "fstp %%st(0);" : "=t"(x));
    return x;
}

float tanf(float x)
{
    __asm__ ("fptan;"
             "fstp %%st(0);" : "=t"(x));
    return x;
}

long double tanl(long double x)
{
    __asm__ ("fptan;"
             "fstp %%st(0);" : "=t"(x));
    return x;
}
