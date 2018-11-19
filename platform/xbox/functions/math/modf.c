#include <math.h>

double modf(double value, double *iptr)
{
    double i = trunc(value);

    *iptr = i;
    return value-i;
}

float modff(float value, float *iptr)
{
    float i = truncf(value);

    *iptr = i;
    return value-i;
}

long double modfl(long double value, long double *iptr)
{
    long double i = truncl(value);

    *iptr = i;
    return value-i;
}
