#include <math.h>

double pow(double x, double y)
{
    return exp(y*log(x));
}

float powf(float x, float y)
{
    return expf(y*logf(x));
}

long double powl(long double x, long double y)
{
    return expl(y*logl(x));
}
