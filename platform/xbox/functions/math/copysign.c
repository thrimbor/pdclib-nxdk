#include <math.h>
#include <assert.h>
#include <stdint.h>

double copysign(double x, double y)
{
    uint32_t *x_raw = (uint32_t *)&x;
    uint32_t *y_raw = (uint32_t *)&y;

    x_raw[1] = (x_raw[1] & 0x7FFFFFFF) | (y_raw[1] & 0x80000000);
    return x;
}

float copysignf(float x, float y)
{
    uint32_t *x_raw = (uint32_t *)&x;
    uint32_t *y_raw = (uint32_t *)&y;

    *x_raw = (*x_raw & 0x7FFFFFFF) | (*y_raw & 0x80000000);
    return x;
}

long double copysignl(long double x, long double y)
{
    uint32_t *x_raw = (uint32_t *)&x;
    uint32_t *y_raw = (uint32_t *)&y;

    x_raw[1] = (x_raw[1] & 0x7FFFFFFF) | (y_raw[1] & 0x80000000);
    return x;
}
