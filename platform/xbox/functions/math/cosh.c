#include <math.h>

double cosh(double x)
{
    if (x == NAN)
        return NAN;

    double r = (exp(x) + exp(-x)) / 2.0;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
        return HUGE_VAL;

    return r;
}

float coshf(float x)
{
    if (x == NAN)
        return NAN;

    float r = (expf(x) + expf(-x)) / 2.0f;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
        return HUGE_VALF;

    return r;
}

long double coshl(long double x)
{
    if (x == NAN)
        return NAN;

    long double r = (expl(x) + expl(-x)) / 2.0;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
        return HUGE_VAL;

    return r;
}
