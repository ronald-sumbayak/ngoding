#include <cstdio>

int main (int argc, char const *argv[]) {
    long long tc, n, k, x;
    scanf ("%lld", &tc);
    while (tc--) {
        scanf ("%lld %lld", &n, &k);
        printf ("%d\n", (int) (k ^ (k >> 1)));
    }
    return 0;
}