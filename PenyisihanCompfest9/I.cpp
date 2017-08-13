#include <cstdio>
#include <algorithm>
#include <climits>

int main (int argc, char **argv) {
    int tc, n, k;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &n, &k);
        int salary[n];
    
        for (int i = 0; i < n; i++)
            scanf ("%d", &salary[i]);
    
        std::sort (salary, salary + n);
        
        int min = salary[n - 1] - salary[0];
        for (int i = 0; i <= k; i++) {
            int range = salary[n-k-1+i] - salary[i];
            if (range < min) min = range;
        }
    
        printf ("%d\n", min);
    }
}