#include <math.h>

double floor(double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "andl %4, %2;"   // clear rounding bits in control word
             "orl %3, %2;"    // set rounding mode to "round down"
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0x400), "r"(~0xc00) : "eax");
    return x;
}

float floorf(float x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "andl %4, %2;"   // clear rounding bits in control word
             "orl %3, %2;"    // set rounding mode to "round down"
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0x400), "r"(~0xc00) : "eax");
    return x;
}

long double floorl(long double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"     // backup FPU control word
             "mov %2, %%eax;"
             "andl %4, %2;"   // clear rounding bits in control word
             "orl %3, %2;"    // set rounding mode to "round down"
             "fldcw %2;"      // load modified control word
             "frndint;"       // round the float
             "mov %%eax, %2;"
             "fldcw %2;"      // restore original control word
             : "=t"(x) : "0"(x), "m"(fcw), "r"(0x400), "r"(~0xc00) : "eax");
    return x;
}
