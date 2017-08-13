#include <cstdio>

long long gcd (long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    
    return a;
}

int main () {
    int tc, n;
    scanf ("%d %d", &tc, &n);
    
    while (tc--) {
        int numb[n];
        for (int x = 0; x < n; x++) scanf ("%d", &numb[x]);
    
        long long result = 0;
    
        for (int i = n-1; i > 0; i--) {
            result += (numb[i] | numb[i-1]) * i;
        }
        
        int div;
        div = (n * (n-1)) / 2;
    
        long long fpb;
        fpb = gcd (result, div);
    
        printf ("%lld/%lld\n", result/fpb, div/fpb);
    }
}