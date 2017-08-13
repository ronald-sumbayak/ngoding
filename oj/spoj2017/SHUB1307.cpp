#include <cstdio>

int main (int argc, char **argv) {
    int tc, n, m, k;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d %d", &n, &m, &k);
        bool s[n][m][k+5]={};
        int vs[n][m];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf ("%d", &vs[i][j]);
        
        if (vs[0][0] <= k) s[0][0][vs[0][0]] = true;
        
        for (int i = 1; i < n; i++)
            for (int j = vs[i][0]; j <= k; j++)
                s[i][0][j] = s[i-1][0][j-vs[i][0]];
        
        for (int i = 1; i < m; i++)
            for (int j = vs[0][i]; j <= k; j++)
                s[0][i][j] = s[0][i-1][j-vs[0][i]];
    
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                for (int x = vs[i][j]; x <= k; x++)
                    s[i][j][x] = s[i-1][j][x-vs[i][j]] || s[i][j-1][x-vs[i][j]] || s[i-1][j-1][x-vs[i][j]];
        
        while (k >= 0) {
            if (s[n-1][m-1][k]) break;
            k--;
        }
        printf ("%d\n", k);
    }
}