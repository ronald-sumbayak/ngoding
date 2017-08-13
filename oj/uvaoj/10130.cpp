#include <cstdio>
#include <vector>
using namespace std;

int main (int argc, char **argv) {
    int tc;
    int n, g, mw, p[1005], w[1005];
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf ("%d %d", &p[i], &w[i]);
        scanf ("%d", &g);
    
        int dp[1005][33]={};
        int total = 0;
        while (g--) {
            scanf ("%d", &mw);
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= mw; j++) {
                    if (j < w[i])
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = max (dp[i-1][j], dp[i-1][j-w[i]] + p[i]);
                }
            }
            total += dp[n][mw];
        }
        
        printf ("%d\n", total);
    }
}