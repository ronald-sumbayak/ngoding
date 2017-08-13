#include <cstdio>

int main (int argc, char **argv) {
    int n;
    
    while (scanf ("%d", &n) && n) {
        int a=0, b=0;
        for (int i = 1, j = 0; n; i <<= 1, n >>= 1)
            if (n & 1)
                if (j++ & 1) b |= i;
                else a |= i;
        
        printf ("%d %d\n", a, b);
    }
}