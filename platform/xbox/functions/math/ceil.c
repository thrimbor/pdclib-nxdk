#include <math.h>

double ceil(double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0x800) : "eax");
    return x;
}

float ceilf(float x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0x800) : "eax");
    return x;
}

long double ceill(long double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0x800) : "eax");
    return x;
}
