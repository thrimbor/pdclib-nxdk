#include <fenv.h>
#include <assert.h>
#include <stdlib.h>

int feclearexcept (int excepts)
{
    if ((excepts & FE_ALL_EXCEPT) != excepts) {
        return -1;
    }

    if (excepts == FE_ALL_EXCEPT) {
        __asm__ ("fnclex;");
    } else {
        fenv_t fenv;
        fegetenv(&fenv);
        fenv.status &= ~excepts;
        fesetenv(&fenv);
    }

    return 0;
}

int fegetexceptflag (fexcept_t *flagp, int excepts)
{
    assert(flagp != NULL);

    if ((excepts & FE_ALL_EXCEPT) != excepts) {
        return -1;
    }

    unsigned short sw;
    __asm__ ("fnstsw %0;" : : "m"(sw));
    *flagp = sw & excepts;

    return 0;
}

int feraiseexcept (int excepts)
{
    if ((excepts & FE_ALL_EXCEPT) != excepts) {
        return -1;
    }

    fexcept_t flags = excepts;
    fesetexceptflag(&flags, excepts);
    __asm__ ("fwait;");

    return 0;
}

int fesetexceptflag (const fexcept_t *flagp, int excepts)
{
    assert(flagp != NULL);

    if ((excepts & FE_ALL_EXCEPT) != excepts) {
        return -1;
    }

    fenv_t fenv;
    fegetenv(&fenv);
    fenv.status &= ~excepts;
    fenv.status |= *flagp & excepts;
    fesetenv(&fenv);

    return 0;
}

int fetestexcept (int excepts)
{
    unsigned short sw;
    __asm__ ("fnstsw %0;" : : "m"(sw));
    return sw & excepts;
}
