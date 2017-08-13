#include <cstdio>
typedef long long ll;

int main (int argc, char **argv) {
    int sz, p;
    
    while (scanf ("%d %d", &sz, &p) && sz||p) {
        ll w = 1;
        while (w*w < p) w += 2;
        
        if (w == 1) {
            printf ("Line = %d, column = %d.\n", (sz/2)+1, (sz/2)+1);
            continue;
        }
        
        ll lb = (w-2)*(w-2);
        ll pad = (sz-w)/2;
        ll x, y;
        
        if (p <= lb + w-1) {
            x = (lb+w)-p+pad;
            y = sz - pad;
        }
        else if (p <= lb + (2*(w-1))) {
            x = pad + 1;
            y = lb+(2*(w-1))-p+pad+1;
        }
        else if (p <= lb + 3*(w-1)) {
            x = p-(lb+(2*(w-1)))+pad+1;
            y = pad + 1;
        }
        else {
            x = sz - pad;
            y = p-(lb+(3*(w-1)))+pad+1;
        }
        
        printf ("Line = %lld, column = %lld.\n", y, x);
    }
    
    return 0;
}