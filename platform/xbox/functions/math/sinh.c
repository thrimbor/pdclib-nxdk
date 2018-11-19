#include <math.h>

double sinh(double x)
{
    if (x == NAN)
        return NAN;

    double r = (exp(x) - exp(-x)) / 2.0;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
    {
        if (x > 0.0)
            return HUGE_VAL;
        else
            return -HUGE_VAL;
    }

    return r;
}

float sinhf(float x)
{
    if (x == NAN)
        return NAN;

    float r = (expf(x) - expf(-x)) / 2.0f;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
    {
        if (x > 0.0f)
            return HUGE_VALF;
        else
            return -HUGE_VALF;
    }

    return r;
}

long double sinhl(long double x)
{
    if (x == NAN)
        return NAN;

    double r = (expl(x) - expl(-x)) / 2.0;

    if (((r==INFINITY) || (r==-INFINITY)) && (x!=INFINITY) && (x!=-INFINITY))
    {
        if (x > 0.0)
            return HUGE_VAL;
        else
            return -HUGE_VAL;
    }

    return r;
}
