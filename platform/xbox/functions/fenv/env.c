#include <fenv.h>

int fegetenv (fenv_t *envp)
{
    __asm__ ("fnstenv (%0);" : : "r"(envp));
    return 0;
}

int feholdexcept (fenv_t *envp)
{
    fegetenv(envp);
    feclearexcept(FE_ALL_EXCEPT);
    return 0;
}

int fesetenv (const fenv_t *envp)
{
    __asm__ ("fldenv (%0);" : : "r"(envp));
    return 0;
}

int feupdateenv (const fenv_t *envp)
{
    int exceptions = fetestexcept(FE_ALL_EXCEPT);
    fesetenv(envp);
    feraiseexcept(exceptions);
    return 0;
}
