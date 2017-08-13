#include <cstdio>

int main (int argc, char **argv) {
    int TC, p, m, n, r, c;
    scanf ("%d", &TC);
    
    for (int tc = 1; tc <= TC; tc++) {
        scanf ("%d %d %d %d %d", &p, &m, &n, &r, &c);
    
        char pat[p][m+1][n+1];
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < m; j++) {
                scanf ("%s", pat[i][j]);
            }
        }
        
//        for (int i = 0; i < p; i++) {
//            for (int j = 0; j < m; j++)
//                printf ("%s\n", pat[i][j]);
//            printf ("\n");
//        }
    
        int s = 0, t = 0;
        int y = 0, x = 0;
        char res[r][c+1];
        while (x < c && y < r) {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    res[y + i][x + j] = pat[t][i][j];
            t = (t+1) % p;
            y += m;
            if (y == r) {
                s = (s+1) % p;
                t = s;
                x += n;
                y = 0;
            }
        }
    
        printf ("Case #%d:\n", tc);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                printf ("%c", res[i][j]);
            printf ("\n");
        }
    }
}