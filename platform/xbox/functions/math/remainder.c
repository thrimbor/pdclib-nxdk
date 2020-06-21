#include <math.h>
#include <assert.h>

double remainder(double x, double y)
{
    __asm__ ("fprem1;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}

float remainderf(float x, float y)
{
    __asm__ ("fprem1;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}

long double remainderl(long double x, long double y)
{
    __asm__ ("fprem1;" : "=t"(x) : "0"(x), "u"(y));
    return x;
}
