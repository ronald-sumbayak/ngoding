#include <algorithm>
#include <cstdio>

int main (int argc, char **argv) {
    int n, x;
    
    while (scanf ("%d", &n) != EOF) {
        int c = 1 << n;
        int m = 0;
        int p[c]={};
        
        for (int i = 0; i < c; i++) {
            scanf ("%d", &x);
            for (int j = 1; j < c; j <<= 1)
                p[i^j] += x;
        }
        
        for (int i = 0; i < c; i++)
            for (int j = 1; j < c; j <<= 1)
                m = std::max (m, p[i]+p[i^j]);
        printf ("%d\n", m);
    }
    
    return 0;
}