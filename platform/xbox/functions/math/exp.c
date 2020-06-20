#include <math.h>
#include <stdint.h>

double exp(double x)
{
    uint32_t *raw_bits = (uint32_t *)&x;
    if ((raw_bits[1] & 0x7FFFFFFF) >= 0x7FF00000) {
        // value is -INFINITY, INFINITY, -NAN or NAN
        if (raw_bits[1] == 0xFFF00000 && raw_bits[0] == 0) {
            // value is -INFINITY
            return 0;
        }
        return x;
    }

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
    uint32_t *raw_bits = (uint32_t *)&x;
    if ((*raw_bits & 0x7FFFFFFF) >= 0x7F800000) {
        // value is -INFINITY, INFINITY, -NAN or NAN
        if (*raw_bits == 0xFF800000) {
            // value is -INFINITY
            return 0;
        }
        return x;
    }

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
    uint32_t *raw_bits = (uint32_t *)&x;
    if ((raw_bits[1] & 0x7FFFFFFF) >= 0x7FF00000) {
        // value is -INFINITY, INFINITY, -NAN or NAN
        if (raw_bits[1] == 0xFFF00000 && raw_bits[0] == 0) {
            // value is -INFINITY
            return 0;
        }
        return x;
    }

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
