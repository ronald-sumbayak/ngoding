#include <stdio.h>
#define MOD 1000000007

long long mod_exp (long long b, long long e, long long m) {
    long long r = 1;
    while (e > 0) {
        if ((e & 1) == 1) r = (r * b) % m;
        e >>= 1;
        b = (b * b) % m;
    }
    return r;
}

int main (int argc, char const *args[]) {
    long long n, result;
    long long inv3 = mod_exp (3, MOD-2, MOD);
    scanf ("%lld", &n);
    result = ((mod_exp (4, n, MOD) + 2) * inv3) % MOD;
    printf ("%lld", result);
    return 0;
}