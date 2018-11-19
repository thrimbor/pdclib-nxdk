#include <math.h>

double trunc(double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}

float truncf(float x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}

long double truncl(long double x)
{
    unsigned short fcw;

    __asm__ ("fnstcw %2;"
             "mov %2, %%eax;"
             "orl %3, %2;"
             "fldcw %2;"
             "frndint;"
             "mov %%eax, %2;"
             "fldcw %2;" : "=t"(x) : "0"(x), "m"(fcw), "r"(0xC00) : "eax");
    return x;
}
