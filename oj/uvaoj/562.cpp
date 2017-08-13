#include <algorithm>
#include <cstdio>

int coins[1000];
int dp[101][25000];

int solution (int m, int n, int limit) {
    if (n > limit) return 0;
    if (m == 0) return n;
    if (dp[m][n] == 0) 
        dp[m][n] = std::max (solution (m-1, n, limit), solution (m-1, n+coins[m-1], limit));
    return dp[m][n];
}

int main () {
    int tc;
    scanf ("%d", &tc);
    
    while (tc--) {
        int c, sum=0;
        scanf ("%d", &c);
        for (int i = 0; i < c; i++) {
            scanf ("%d", &coins[i]);
            sum += coins[i];
        }
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= (sum/2)+1; j++) {
                dp[i][j] = 0;
            }
        }
        int s = solution (c, 0, sum/2);
        printf ("%d\n", sum - (s * 2));
    }
    
}