#include <math.h>

double trunc(double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "orl %3, %2;"    // set all rounding bits in control word ("chop" mode)
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}

float truncf(float x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "orl %3, %2;"    // set all rounding bits in control word ("chop" mode)
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}

long double truncl(long double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "orl %3, %2;"    // set all rounding bits in control word ("chop" mode)
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}
