#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main (int argc, char **argv) {
    char a[50005], b[50005];
    scanf ("%s %s", a, b);
    
    int m, n;
    m = strlen (a);
    n = strlen (b);
    int *now = new int[n+1] ();
    int *prev = new int[n+1] ();
    
    for (int i = 1; i <= m; i++) {
        swap (now, prev);
        for (int j = 1; j <= n; j++)
            if (a[i - 1] == b[j - 1])
                now[j] = prev[j - 1] + 1;
            else
                now[j] = max (prev[j], now[j - 1]);
    }
    
    printf ("%d", now[n]);
}