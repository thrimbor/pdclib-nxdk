#include <math.h>

double tanh(double x)
{
    if (x == NAN)
        return NAN;
    else if (x == INFINITY)
        return 1.0;
    else if (x == -INFINITY)
        return -1.0;
    else
        return sinh(x) / cosh(x);
}

float tanhf(float x)
{
    if (x == NAN)
        return NAN;
    else if (x == INFINITY)
        return 1.0f;
    else if (x == -INFINITY)
        return -1.0f;
    else
        return sinhf(x) / coshf(x);
}

long double tanhl(long double x)
{
    if (x == NAN)
        return NAN;
    else if (x == INFINITY)
        return 1.0;
    else if (x == -INFINITY)
        return -1.0;
    else
        return sinhl(x) / coshl(x);
}
