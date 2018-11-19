#include <math.h>

double acos(double x)
{
    if (x < -1.0 || x > 1.0)
        return NAN;

    return 1.570796326794896619 - asin(x);
}

float acosf(float x)
{
    if (x < -1.0f || x > 1.0f)
        return NAN;

    return 1.570796326794896619f - asinf(x);
}

long double acosl(long double x)
{
    if (x < -1.0 || x > 1.0)
        return NAN;

    return 1.570796326794896619 - asinl(x);
}
