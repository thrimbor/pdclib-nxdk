#include <math.h>

double ldexp(double x, int exp)
{
    __asm__ ("fscale;"
             "fst %%st(0);" : "=t"(x) : "0"(x), "u"((double)exp));

    return x;
}

float ldexpf(float x, int exp)
{
    __asm__ ("fscale;"
             "fst %%st(0);" : "=t"(x) : "0"(x), "u"((float)exp));

    return x;
}

long double ldexpl(long double x, int exp)
{
    __asm__ ("fscale;"
             "fst %%st(0);" : "=t"(x) : "0"(x), "u"((long double)exp));

    return x;
}
