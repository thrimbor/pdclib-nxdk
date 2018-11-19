#include <math.h>

double log(double x)
{
    if (x <= 0.0) return NAN;

    __asm__ ("fyl2x;"
             "fldl2e;"
             "fdivrp" : "=t"(x) : "0"(x), "u"(1.0));
    return x;
}

float logf(float x)
{
    if (x <= 0.0f) return NAN;

    __asm__ ("fyl2x;"
             "fldl2e;"
             "fdivrp" : "=t"(x) : "0"(x), "u"(1.0f));
    return x;
}

long double logl(long double x)
{
    if (x <= 0.0) return NAN;

    __asm__ ("fyl2x;"
             "fldl2e;"
             "fdivrp" : "=t"(x) : "0"(x), "u"(1.0));
    return x;
}
