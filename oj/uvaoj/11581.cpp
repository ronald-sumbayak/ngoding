#include <cstdio>

int **create_new () {
    int **a = new int *[3];
    for (int i = 0; i < 3; i++) a[i] = new int[3];
    return a;
}

int **f (int **g) {
    int **h = create_new ();
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            if (i > 0) sum += g[i-1][j];
            if (i < 2) sum += g[i+1][j];
            if (j > 0) sum += g[i][j-1];
            if (j < 2) sum += g[i][j+1];
            h[i][j] = sum % 2;
        }
    
    return h;
}

bool isZero (int **g) {
    for (int i = 0; i < 9; i++) if (g[i/3][i%3] == 1) return false;
    return true;
}

int main (int argc, char **argv) {
    int tc, **g, ans;
    char c[4];
    scanf ("%d", &tc);
    
    while (tc--) {
        g = create_new ();
        
        for (int i = 0; i < 3; i++) {
            scanf ("%s", c);
            for (int j = 0; j < 3; j++) g[i][j] = c[j] - '0';
        }
        
        ans = -1;
        while (!isZero (g)) {
            g = f (g);
            ans++;
        }
        printf ("%d\n", ans);
    }
    
    return 0;
}