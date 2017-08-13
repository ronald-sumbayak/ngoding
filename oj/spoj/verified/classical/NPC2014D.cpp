#include <cstdio>
#include <cstdlib>

int main (int argc, char **argv) {
    long long tc, n;
    scanf ("%lld", &tc);
    
    for (int t = 1; t <= tc; t++) {
        scanf ("%lld", &n);
        long long max=0, prev=0, step=0, town, soldiers=0;
        
        while (n--) {
            scanf ("%lld", &town);
            if (town+step >= max) {
                if (town > max) max = town;
                soldiers++;
                step = 0;
            }
            step++;
        }
        
        printf ("%lld\n", soldiers+max);
    }
    
    return 0;
}