#include <math.h>

double fmod(double x, double y)
{
    if (y == 0.0)
        return NAN;

    __asm__ ("fprem;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}

float fmodf(float x, float y)
{
    if (y == 0.0f)
        return NAN;

    __asm__ ("fprem;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}

long double fmodl(long double x, long double y)
{
    if (y == 0.0)
        return NAN;

    __asm__ ("fprem;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}
