#ifndef _PDCLIB_MATH_H
#define _PDCLIB_MATH_H _PDCLIB_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef float float_t;
typedef double double_t;

#define HUGE_VAL (__builtin_huge_val())
#define HUGE_VALF (__builtin_huge_valf())
#define HUGE_VALL (__builtin_huge_vall())

#define INFINITY (__builtin_inff())

#define NAN (__builtin_nanf(""))

// immitate ReactOS's trick of modeling these after FPU status word flags
#define FP_NAN 0x0100
#define FP_NORMAL 0x0400
#define FP_INFINITE (FP_NAN | FP_NORMAL)
#define FP_ZERO 0x4000
#define FP_SUBNORMAL (FP_NORMAL | FP_ZERO)

#define FP_FAST_FMAF 1
#define FP_FAST_FMA 1
#define FP_FAST_FMAL 1

#define FP_ILOGB0 // FIXME
#define FP_ILOGBNAN // FIXME

#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2

#define math_errhandling // FIXME

#ifdef _USE_MATH_DEFINES
    // these are non-standard
    #define M_E 2.7182818284590452354
    #define M_LOG2E 1.4426950408889634074
    #define M_LOG10E 0.43429448190325182765
    #define M_LN2 0.69314718055994530942
    #define M_LN10 2.30258509299404568402
    #define M_PI 3.14159265358979323846
    #define M_PI_2 1.57079632679489661923
    #define M_PI_4 0.78539816339744830962
    #define M_1_PI 0.31830988618379067154
    #define M_2_PI 0.63661977236758134308
    #define M_2_SQRTPI 1.12837916709551257390
    #define M_SQRT2 1.41421356237309504880
    #define M_SQRT1_2 0.70710678118654752440
#endif

static inline int __fp_unordered_compare (long double x, long double y)
{
    unsigned short sw;
    __asm__ ("fucom;"  // compare st(0) with st(1)
             "fnstsw;" // store status word in ax (sw variable)
             : "=a"(sw) : "t"(x), "u"(y));
    return sw;
}

int __fpclassifyf (float x);
int __fpclassify (double x);
int __fpclassifyl (long double x);
int __signbitf (float x);
int __signbit (double x);
int __signbitl (long double x);

#ifndef __cplusplus
    #define fpclassify(x) (sizeof(x) == sizeof(float) ? __fpclassifyf(x) : sizeof(x) == sizeof(double) ? __fpclassify(x) : __fpclassifyl(x))
    #define isfinite(x) ((fpclassify(x) & FP_NAN) == 0)
    #define isinf(x) (fpclassify(x) == FP_INFINITE)
    #define isnan(x) (fpclassify(x) == FP_NAN)
    #define isnormal(x) (fpclassify(x) == FP_NORMAL)
    #define signbit(x) (sizeof(x) == sizeof(float) ? __signbitf(x) : sizeof(x) == sizeof(double) ? __signbit(x) : __signbitl(x))

    // 7.12.14
    #define isgreater(x, y) ((__fp_unordered_compare((x), (y)) & 0x4500) == 0)
    #define isgreaterequal(x, y) ((__fp_unordered_compare((x), (y)) & FP_INFINITE) == 0)
    #define isless(x, y) ((__fp_unordered_compare((y), (x)) & 0x4500) == 0)
    #define islessequal(x, y) ((__fp_unordered_compare((y), (x)) & FP_INFINITE) == 0)
    #define islessgreater(x, y) ((__fp_unordered_compare((x), (y)) & FP_SUBNORMAL) == 0)
    #define isunordered(x, y) ((__fp_unordered_compare((x), (y)) & 0x4500) == 0x4500)
#else
    extern "C++"
    {
        inline int fpclassify (float x) { return __fpclassifyf(x); };
        inline int fpclassify (double x) { return __fpclassify(x); };
        inline int fpclassify (long double x) { return __fpclassifyl(x); };
        template <typename T>
        inline int isfinite (T x) { return #define isfinite(x) ((fpclassify(x) & FP_NAN) == 0); };
        template <typename T>
        inline int isinf (T x) { return (fpclassify(x) == FP_INFINITE); };
        template <typename T>
        inline int isnan (T x) { return (fpclassify(x) == FP_NAN); };
        template <typename T>
        inline int isnormal (T x) { return (fpclassify(x) == FP_NORMAL); };
        inline int signbit (float x) { return __signbitf(x); };
        inline int signbit (double x) { return __signbit(x); };
        inline int signbit (long double x) { return __signbitl(x); };

        template <typename T1, typename T2>
        inline int isgreater (T1 x, T2 y) { return ((__fp_unordered_compare((x), (y)) & 0x4500) == 0); };
        template <typename T1, typename T2>
        inline int isgreaterequal (T1 x, T2 y) { return ((__fp_unordered_compare((x), (y)) & FP_INFINITE) == 0); };
        template <typename T1, typename T2>
        inline int isless (T1 x, T2 y) { return ((__fp_unordered_compare((y), (x)) & 0x4500) == 0); };
        template <typename T1, typename T2>
        inline int islessequal (T1 x, T2 y) { return ((__fp_unordered_compare((y), (x)) & FP_INFINITE) == 0); };
        template <typename T1, typename T2>
        inline int islessgreater (T1 x, T2 y) { return ((__fp_unordered_compare((x), (y)) & FP_SUBNORMAL) == 0); };
        template <typename T1, typename T2>
        inline int isunordered (T1 x, T2 y) { return ((__fp_unordered_compare((x), (y)) & 0x4500) == 0x4500); };
    }
#endif

// 7.12.4
double acos(double x);
float acosf(float x);
long double acosl(long double x);

double asin(double x);
float asinf(float x);
long double asinl(long double x);

double atan(double x);
float atanf(float x);
long double atanl(long double x);

double atan2(double y, double x);
float atan2f(float y, float x);
long double atan2l(long double y, long double x);

double cos(double x);
float cosf(float x);
long double cosl(long double x);

double sin(double x);
float sinf(float x);
long double sinl(long double x);

double tan(double x);
float tanf(float x);
long double tanl(long double x);

// 7.12.5
double acosh(double x);
float acoshf(float x);
long double acoshl(long double x);

double asinh(double x);
float asinhf(float x);
long double asinhl(long double x);

double atanh(double x);
float atanhf(float x);
long double atanhl(long double x);

double cosh(double x);
float coshf(float x);
long double coshl(long double x);

double sinh(double x);
float sinhf(float x);
long double sinhl(long double x);

double tanh(double x);
float tanhf(float x);
long double tanhl(long double x);

// 7.12.6
double exp(double x);
float expf(float x);
long double expl(long double x);

double exp2(double x);
float exp2f(float x);
long double exp2l(long double x);

double expm1(double x);
float expm1f(float x);
long double expm1l(long double x);

double frexp(double value, int *exp);
float frexpf(float value, int *exp);
long double frexpl(long double value, int *exp);

int ilogb(double x);
int ilogbf(float x);
int ilogbl(long double x);

double ldexp(double x, int exp);
float ldexpf(float x, int exp);
long double ldexpl(long double x, int exp);

double log(double x);
float logf(float x);
long double logl(long double x);

double log10(double x);
float log10f(float x);
long double log10l(long double x);

double log1p(double x);
float log1pf(float x);
long double log1pl(long double x);

double log2(double x);
float log2f(float x);
long double log2l(long double x);

double logb(double x);
float logbf(float x);
long double logbl(long double x);

double modf(double value, double *iptr);
float modff(float value, float *iptr);
long double modfl(long double value, long double *iptr);

double scalbn(double x, int n);
float scalbnf(float x, int n);
long double scalbnl(long double x, int n);
double scalbln(double x, long int n);
float scalblnf(float x, long int n);
long double scalblnl(long double x, long int n);

// 7.12.7
double cbrt(double x);
float cbrtf(float x);
long double cbrtl(long double x);

double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

double hypot(double x, double y);
float hypotf(float x, float y);
long double hypotl(long double x, long double y);

double pow(double x, double y);
float powf(float x, float y);
long double powl(long double x, long double y);

double sqrt(double x);
float sqrtf(float x);
long double sqrtl(long double x);

// 7.12.8
double erf(double x);
float erff(float x);
long double erfl(long double x);

double erfc(double x);
float erfcf(float x);
long double erfcl(long double x);

double lgamma(double x);
float lgammaf(float x);
long double lgammal(long double x);

double tgamma(double x);
float tgammaf(float x);
long double tgammal(long double x);

// 7.12.9
double ceil(double x);
float ceilf(float x);
long double ceill(long double x);

double floor(double x);
float floorf(float x);
long double floorl(long double x);

double nearbyint(double x);
float nearbyintf(float x);
long double nearbyintl(long double x);

double rint(double x);
float rintf(float x);
long double rintl(long double x);

long int lrint(double x);
long int lrintf(float x);
long int lrintl(long double x);
long long int llrint(double x);
long long int llrintf(float x);
long long int llrintl(long double x);

double round(double x);
float roundf(float x);
long double roundl(long double x);

long int lround(double x);
long int lroundf(float x);
long int lroundl(long double x);
long long int llround(double x);
long long int llroundf(float x);
long long int llroundl(long double x);

double trunc(double x);
float truncf(float x);
long double truncl(long double x);

// 7.12.10
double fmod(double x, double y);
float fmodf(float x, float y);
long double fmodl(long double x, long double y);

double remainder(double x, double y);
float remainderf(float x, float y);
long double remainderl(long double x, long double y);

double remquo(double x, double y, int *quo);
float remquof(float x, float y, int *quo);
long double remquol(long double x, long double y, int *quo);

// 7.12.11
double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

double nan(const char *tagp);
float nanf(const char *tagp);
long double nanl(const char *tagp);

double nextafter(double x, double y);
float nextafterf(float x, float y);
long double nextafterl(long double x, long double y);

double nexttoward(double x, long double y);
float nexttowardf(float x, long double y);
long double nexttowardl(long double x, long double y);

// 7.12.12
double fdim(double x, double y);
float fdimf(float x, float y);
long double fdiml(long double x, long double y);

double fmax(double x, double y);
float fmaxf(float x, float y);
long double fmaxl(long double x, long double y);

double fmin(double x, double y);
float fminf(float x, float y);
long double fminl(long double x, long double y);

// 7.12.13
double fma(double x, double y, double z);
float fmaf(float x, float y, float z);
long double fmal(long double x, long double y, long double z);

#ifdef __cplusplus
}
#endif

#endif
