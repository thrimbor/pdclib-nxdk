#include <math.h>

int __signbitf (float x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & 0x0200; // mask all except C1, which contains the sign bit
}

int __signbit (double x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & 0x0200; // mask all except C1, which contains the sign bit
}

int __signbitl (long double x)
{
    unsigned short sw;
    __asm__ ("fxam;"   // examine st(0)
             "fstsw;"  // store status word in ax (sw variable) and do exception check
             : "=a"(sw) : "t"(x));
    return sw & 0x0200; // mask all except C1, which contains the sign bit
}
