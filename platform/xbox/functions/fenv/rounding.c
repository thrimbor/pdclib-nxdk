#include <fenv.h>

int fegetround (void)
{
    unsigned short fcw;
    __asm__ ("fnstcw  %0;" : : "m"(fcw));
    return fcw & 0xc00;
}

int fesetround (int round)
{
    if (round != FE_DOWNWARD && round != FE_TONEAREST && round != FE_TOWARDZERO && round != FE_UPWARD) {
        return -1;
    }

    unsigned short fcw;
    __asm__ ("fnstcw %0;"   // store control word
             "andl %1, %0;" // mask out all rounding flags
             "orl %2, %0;"  // set rounding mode flags
             "fldcw %0;"    // load control word
             : : "m"(fcw), "r"(0xc00), "r"(round));
    return 0;
}
