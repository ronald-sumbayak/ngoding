#include <algorithm>
#include <cstdio>
#include <stack>

int main (int argc, char **argv) {
    int n, cd;
    while (scanf ("%d", &n) != EOF) {
        scanf ("%d", &cd);
        int cds[cd];

        for (int i = 1; i <= cd; i++)
            scanf ("%d", &cds[i]);

        int dp[cd+1][n+1]={};
        bool ch[cd+1][n+1]={};

        for (int i = 1; i <= cd; i++)
            for (int j = 0; j <= n; j++)
                if (j < cds[i])
                    dp[i][j] = dp[i-1][j];
                else {
                    int a, b;
                    a = dp[i-1][j];
                    b = dp[i-1][j-cds[i]] + cds[i];

                    dp[i][j] = std::max (a, b);
                    if (b >= a) ch[i][j] = true;}

        std::stack<int> tracks;
        for (int i=cd, j=n; i>=0 && j>=0; i--)
            if (ch[i][j]) {
                tracks.push (cds[i]);
                j -= cds[i];
            }
        
        while (!tracks.empty ()) {
            printf ("%d ", tracks.top ());
            tracks.pop ();}
        printf ("sum:%d\n", dp[cd][n]);
    }
}
