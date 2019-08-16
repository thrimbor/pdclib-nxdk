#include <math.h>
#include <assert.h>

double fmax(double x, double y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? y : x;
    }

    return x < y ? y : x;
}

float fmaxf(float x, float y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? y : x;
    }

    return x < y ? y : x;
}

long double fmaxl(long double x, long double y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? y : x;
    }

    return x < y ? y : x;
}
