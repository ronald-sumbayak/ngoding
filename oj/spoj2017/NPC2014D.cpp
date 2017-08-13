#include <cstdio>

int main (int argc, char **argv) {
    int tc, n, p;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d", &n);
        int s = 0;
        
        for (int i = 0; i < n; i++) {
            scanf ("%d", &p);
            if (s-i-p < 0) s += p-(s-i);}
        
        printf ("%d\n", s);
    }
}