#include <math.h>

double log(double x)
{
    __asm__ ("fldln2;"
             "fxch;"
             "fyl2x;" : "=t"(x) : "0"(x));
    return x;
}

float logf(float x)
{
    __asm__ ("fldln2;"
             "fxch;"
             "fyl2x;" : "=t"(x) : "0"(x));
    return x;
}

long double logl(long double x)
{
    __asm__ ("fldln2;"
             "fxch;"
             "fyl2x;" : "=t"(x) : "0"(x));
    return x;
}
