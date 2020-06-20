#include <math.h>

double pow(double x, double y)
{
    if (x < 0.0 && y != trunc(y)) {
        // Negative base and non-integer exponent
        return -NAN;
    }

    float r = exp(y * log(fabs(x)));

    if (x < 0.0 && remainder(y, 2.0) != 0) {
        r = -r;
    }

    return r;
}

float powf(float x, float y)
{
    if (x < 0.0f && y != truncf(y)) {
        // Negative base and non-integer exponent
        return -NAN;
    }

    float r = expf(y * logf(fabsf(x)));

    if (x < 0.0f && remainderf(y, 2.0f) != 0) {
        r = -r;
    }

    return r;
}

long double powl(long double x, long double y)
{
    if (x < 0.0 && y != truncl(y)) {
        // Negative base and non-integer exponent
        return -NAN;
    }

    float r = expl(y * logl(fabsl(x)));

    if (x < 0.0 && remainderl(y, 2.0) != 0) {
        r = -r;
    }

    return r;
}
