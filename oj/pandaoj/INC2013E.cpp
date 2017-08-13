#include <cstdio>
#include <algorithm>
#include <vector>

int getNumb () {
    int r=0;
    int c;
    
    while (true) {
        c = getchar_unlocked ();
        if (c == ' ' || c == '\n') continue;
        else break;
    }
    
    if (c != '-') r = r + c - '0';
    
    while (true) {
        c = getchar_unlocked ();
        if (c >= '0' && c <= '9') r = 10 * r + c -'0';
        else break;
    }
    
    return r;
}

int main (int argc, char **argv) {
    int tc, n;
    tc = getNumb ();
    
    for (int t = 1; t <= tc; t++) {
        n = getNumb ();
        int p[n+1];
        p[0] = 0;
        for (int i = 1; i <= n; i++)
            p[i] = getNumb (), p[i] ^= p[i-1];
        std::sort (p, p+n+1);
        
        int i=0, res=0;
        for (int j = 1; j <= n; j++)
            if (p[j] != p[j-1]) {
                res += (j-i) * (j-i-1) / 2;
                i = j;
            }
        
        printf ("Case #%d: %d\n", t, res + ((n+1-i) * (n-i) / 2));
    }
}