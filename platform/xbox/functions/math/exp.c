#include <math.h>

double exp(double x)
{
    __asm__ ("fldl2e;"
             "fmulp;"
             "fld %%st(0);"
             "frndint;"
             "fld1;"
             "fscale;"
             "fxch %%st(2);"
             "fsubp %%st(1);"
             "f2xm1;"
             "fld1;"
             "faddp;"
             "fmulp" : "+t"(x));
    return x;
}

float expf(float x)
{
    __asm__ ("fldl2e;"
             "fmulp;"
             "fld %%st(0);"
             "frndint;"
             "fld1;"
             "fscale;"
             "fxch %%st(2);"
             "fsubp %%st(1);"
             "f2xm1;"
             "fld1;"
             "faddp;"
             "fmulp" : "+t"(x));
    return x;
}

long double expl(long double x)
{
    __asm__ ("fldl2e;"
             "fmulp;"
             "fld %%st(0);"
             "frndint;"
             "fld1;"
             "fscale;"
             "fxch %%st(2);"
             "fsubp %%st(1);"
             "f2xm1;"
             "fld1;"
             "faddp;"
             "fmulp" : "+t"(x));
    return x;
}
