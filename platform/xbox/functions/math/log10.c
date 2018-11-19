#include <math.h>

double log10(double x)
{
    if (x <= 0.0)
        return NAN;

    __asm__ ("fyl2x;"
             "fldl2t;"
             "fdivrp;" : "=t"(x) : "0"(x), "u"(1.0));

    return x;
}

float log10f(float x)
{
    if (x <= 0.0f)
        return NAN;

    __asm__ ("fyl2x;"
             "fldl2t;"
             "fdivrp;" : "=t"(x) : "0"(x), "u"(1.0f));

    return x;
}

long double log10l(long double x)
{
    if (x <= 0.0)
        return NAN;

    __asm__ ("fyl2x;"
             "fldl2t;"
             "fdivrp;" : "=t"(x) : "0"(x), "u"(1.0));

    return x;
}
