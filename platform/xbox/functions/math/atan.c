#include <math.h>

double atan(double x)
{
    __asm__ ("fld1;"
             "fpatan" : "+t"(x));
    return x;
}

float atanf(float x)
{
    __asm__ ("fld1;"
             "fpatan" : "+t"(x));
    return x;
}

long double atanl(long double x)
{
    __asm__ ("fld1;"
             "fpatan" : "+t"(x));
    return x;
}
