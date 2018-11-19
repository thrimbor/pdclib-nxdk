#include <math.h>

double asin(double x)
{
    if (x < -1.0 || x > 1.0)
        return NAN;

    return 2.0 * atan(x / (sqrt(1.0-(x*x))+1.0));
}

float asinf(float x)
{
    if (x < -1.0f || x > 1.0f)
        return NAN;

    return 2.0f * atanf(x / (sqrtf(1.0f-(x*x))+1.0f));
}

long double asinl(long double x)
{
    if (x < -1.0 || x > 1.0)
        return NAN;

    return 2.0 * atanl(x / (sqrtl(1.0-(x*x))+1.0));
}
