// Adapted from public domain code by Danny Smith <dannysmith@users.sourceforge.net>

#include <math.h>
#include <assert.h>


double nexttoward(double x, long double y)
{
    union
    {
        double d;
        unsigned long long ll;
    } u;

    long double xx = x;

    if (isnan (y) || isnan (x)) {
        return x + y;
    }

    if (xx == y) {
        /* nexttoward (0.0, -O.0) should return -0.0.  */
        return y;
    }
    u.d = x;
    if (x == 0.0) {
        u.ll = 1;
        return y > 0.0l ? u.d : -u.d;
    }

    /* Non-extended encodings are lexicographically ordered,
       with implicit "normal" bit.  */
    if (((x > 0.0) ^ (y > xx)) == 0) {
        u.ll++;
    } else {
        u.ll--;
    }
    return u.d;
}

float nexttowardf(float x, long double y)
{
    union
    {
        float f;
        unsigned int i;
    } u;

    long double xx = x;

    if (isnan (y) || isnan (x)) {
        return x + y;
    }

    if (xx == y) {
        /* nexttowardf (0.0, -O.0) should return -0.0.  */
        return y;
    }
    u.f = x;
    if (x == 0.0f) {
        u.i = 1;
        return y > 0.0l ? u.f : -u.f;
    }

    /* Non-extended encodings are lexicographically ordered,
       with implicit "normal" bit.  */
    if (((x > 0.0f) ^ (y > xx)) == 0) {
        u.i++;
    } else {
        u.i--;
    }
    return u.f;
}

long double nexttowardl(long double x, long double y)
{
    static_assert(sizeof(double) == sizeof(long double), "long double and double must be the same size.");

    return nexttoward(x, y);
}
