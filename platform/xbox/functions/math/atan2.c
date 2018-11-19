#include <math.h>

double atan2(double y, double x)
{
    __asm__ ("fpatan;" : "=t"(y) : "0"(x), "u"(y));
    return y;
}

float atan2f(float y, float x)
{
    __asm__ ("fpatan;" : "=t"(y) : "0"(x), "u"(y));
    return y;
}

long double atan2l(long double y, long double x)
{
    __asm__ ("fpatan;" : "=t"(y) : "0"(x), "u"(y));
    return y;
}
