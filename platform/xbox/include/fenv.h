#ifndef _PDCLIB_FENV_H
#define _PDCLIB_FENV_H _PDCLIB_FENV_H

// 7.6.4
// follows the format used by fnstenv/fldenv
typedef struct _fenv_t
{
    unsigned short control;
    unsigned short unused1;
    unsigned short status;
    unsigned short unused2;
    unsigned short tag;
    unsigned short unused3;
    unsigned long other[4];
} fenv_t;

// 7.6.5
typedef unsigned short fexcept_t;

// 7.6.6
// modelled after the x87 status word exception flags
#define FE_INVALID   0x01
#define FE_DIVBYZERO 0x04
#define FE_OVERFLOW  0x08
#define FE_UNDERFLOW 0x10
#define FE_INEXACT   0x20
// 7.6.7
#define FE_ALL_EXCEPT (FE_DIVBYZERO | FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW)

// 7.6.8
// modelled after the x87 rounding flags
#define FE_DOWNWARD   0x400
#define FE_TONEAREST  0x000
#define FE_TOWARDZERO 0xc00
#define FE_UPWARD     0x800

// 7.6.9
static const fenv_t __fe_dfl_env = {0x037f, 0x0000,
                                    0x0000, 0x0000,
                                    0xffff, 0x0000,
                                    0x00000000,
                                    0x00000000,
                                    0x00000000,
                                    0x00000000};
#define FE_DFL_ENV (&__fe_dfl_env)

int feclearexcept (int excepts);
int fegetexceptflag (fexcept_t *flagp, int excepts);
int feraiseexcept (int excepts);
int fesetexceptflag (const fexcept_t *flagp, int excepts);
int fetestexcept (int excepts);

int fegetround (void);
int fesetround (int round);

int fegetenv (fenv_t *envp);
int feholdexcept (fenv_t *envp);
int fesetenv (const fenv_t *envp);
int feupdateenv (const fenv_t *envp);

#endif
