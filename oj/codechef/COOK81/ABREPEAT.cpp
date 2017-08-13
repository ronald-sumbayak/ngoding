#include <cstdio>

int main (int argc, char **argv) {
    int tc, n, k;
    char c;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &n, &k);
        getchar ();
        int sa, a=0, b=0, sub=0;
        for (int i = 0; i < n; i++) {
            scanf ("%c", &c);
            if (c == 'a') a++;
            else if (c == 'b') sub += a, b++;
        }
    
        long long total = sub;
        sa = a;
        for (int i = 1; i < k; i++) {
            total += sub;
            total += (sa * b);
            sa += a;
        }
        
        printf ("%lld\n", total);
    }
    
    return 0;
}