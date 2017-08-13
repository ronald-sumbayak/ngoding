#ifndef LIB_ALGO_H
#define LIB_ALGO_H

int gcd_rec (int a, int b) {
    if (b == 0) return a;
    else return gcd_rec (b, a%b);
}

int gcd_it (int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return b;
}

int lcm (int a, int b) {
    return (a * b) / gcd_it (a, b);
}

int mod_exp (int m, int n, int mod) {
    long long r = 1;
    while (n > 0) {
        if ((n & 1) == 1) r = (r * m) % mod;
        n >>= 1;
        b = (b * b) % mod;
    }
    return r;
}

#endif //LIB_ALGO_H
