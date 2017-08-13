#include <cstdio>
#include <cstring>
#include <cmath>

int tmp[1000002];
int main () {
    int tc;
    scanf ("%d", &tc);
    
    for (int t = 1; t <= tc; t++) {
        int n, vals;
        memset (tmp, 0, sizeof (tmp));
        scanf ("%d", &n);
        
        for (int i = 0; i < n; i++) {
            scanf ("%d", &vals);
            tmp[1]++;
            tmp[vals]++;
            int k = (int) sqrt (vals);
            for (int j = 2; j <= k; j++) {
                if (vals % j == 0) {
                    tmp[j]++;
                    tmp[vals/j]++;
                }
            }
            
            if (k * k == vals) tmp[k]--;
        }
        
        for (int i = 1000000; i > 0; i--) {
            if (tmp[i] >= 3) {
                printf ("Case #%d: %d\n", t, i);
                break;
            }
        }
        
    }
}