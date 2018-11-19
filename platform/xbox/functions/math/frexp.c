#include <math.h>

double frexp(double value, int *exp)
{
    double y;
    __asm__ ("fxtract;"
            : "=t"(value), "=u"(y) : "0"(value));

    if (value >= 1.0 || value<=-1.0)
    {
        value /= 2.0;
        y += 1;
    }

    *exp = (int)y;
    return  value;
}

float frexpf(float value, int *exp)
{
    float y;
    __asm__ ("fxtract;"
            : "=t"(value), "=u"(y) : "0"(value));

    if (value >= 1.0f || value<=-1.0f)
    {
        value /= 2.0f;
        y += 1;
    }

    *exp = (int)y;
    return  value;
}

long double frexpl(long double value, int *exp)
{
    long double y;
    __asm__ ("fxtract;"
            : "=t"(value), "=u"(y) : "0"(value));

    if (value >= 1.0 || value<=-1.0)
    {
        value /= 2.0;
        y += 1;
    }

    *exp = (int)y;
    return  value;
}
