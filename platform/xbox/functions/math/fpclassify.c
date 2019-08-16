#include <math.h>

int __fpclassifyf (float x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & (FP_NAN | FP_NORMAL | FP_ZERO);
}

int __fpclassify (double x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & (FP_NAN | FP_NORMAL | FP_ZERO);
}

int __fpclassifyl (long double x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & (FP_NAN | FP_NORMAL | FP_ZERO);
}
