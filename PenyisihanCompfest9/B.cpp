#include <cstdio>

int main (int argc, char **argv) {
    int tc, n, m, k;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d %d", &n, &m, &k);
        int i;
        
        for (i = 0; i < m && k > 0; i++)
            k -= (n - i);
        
        if (k <= 0)
            for (int j = 0; j < n; j++)
                
                printf ("%d ", (j % i) + 1);
        else
            for (int j = 0; j < n; j++)
                printf ("-1 ");
        printf ("\n");
    }
}