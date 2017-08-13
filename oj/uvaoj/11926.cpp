#include <cstdio>
#include <cstring>
bool time[1000000];

bool isConflict (int a, int b) {
    for (int i = a; i < b && i < 1000000; i++) {
        if (time[i]) return true;
        time[i] = true;
    }
    return false;
}

int main (int argc, char **argv) {
    int n, m, s, e, r;
    
    while (scanf ("%d %d", &n, &m) && (n || m)) {
        memset (time, false, sizeof time);
        bool conflict = false;
        
        for (int i = 0; i < n; i++) {
            scanf ("%d %d", &s, &e);
            if (!conflict) conflict = isConflict (s, e);
        }
        
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d", &s, &e, &r);
            while (s < 1000000) {
                if (!conflict) conflict = isConflict (s, e);
                s += r;
                e += r;
            }
        }
        
        if (conflict) printf ("CONFLICT\n");
        else printf ("NO CONFLICT\n");
    }
    
    return 0;
}