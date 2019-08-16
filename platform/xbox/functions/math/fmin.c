#include <math.h>
#include <assert.h>

double fmin(double x, double y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? x : y;
    }

    return x < y ? x : y;
}

float fminf(float x, float y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? x : y;
    }

    return x < y ? x : y;
}

long double fminl(long double x, long double y)
{
    if (isnan(x)) {
        return y;
    }

    if (isnan(y)) {
        return x;
    }

    if (signbit(x) != signbit(y)) {
        return signbit(x) ? x : y;
    }

    return x < y ? x : y;
}
