#include <algorithm>
#include <cstdio>

bool isSameSign (int a, int b) {
    return a * b >= 0;
}

int getNumb (int n = 0) {
    scanf ("%d", &n);
    return n;
}

int main (int argc, char **argv) {
    int n, prev=0, step=0;
    scanf ("%d", &n);
    
    int T[n];
    for (int i = 0; i < n; i++) T[i] = getNumb ();
    for (int i = 0; i < n; i++) T[i] = getNumb () - T[i];
    for (int i = 0; i < n; i++) {
        if (!isSameSign (T[i], T[i-1])) prev = 0;
        if (abs (T[i]) > abs (prev)) step += abs (T[i]-prev);
        prev = T[i];
    }
    
    printf ("%d\n", step);
    return 0;
}