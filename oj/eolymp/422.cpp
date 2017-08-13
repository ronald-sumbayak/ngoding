#include <cstdio>

int main () {
    long long n;
    scanf ("%lld", &n);

    long long limit;
    limit = n % 2 == 0 ? n / 2 : (n / 2) + 1;
    
    long long result;
    result = ((n * (n - 1)) / 2) + limit;
    
    long long skipped10 = result / 10;
    result += skipped10;
    
    while (result / 10 > skipped10) {
        long long skipped = result / 10;
        result += skipped - skipped10;
        skipped10 = skipped;
    }
    
    printf ("%lld\n", result);
}