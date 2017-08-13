#include <bits/stdc++.h>
using namespace std;
int dp[2001][2001];
int s[2009];
int p[2];

int f (int start, int end) {
    if(start > end)
        return 0;
    if(dp[start][end] == -1000001) {
        if (end == start) {
            dp[start][end] =
                max (f (start+1, end) + s[start], f (start, end-1) + s[end]);
        }
        else {
            dp[start][end] =
                max (f (start+1, end) + s[start],
                     max (f (start+2, end) + s[start] + s[start+1],
                          max (f (start, end-1) + s[end], f (start, end-2) + s[end] + s[end-1])));
        }
    }
        
    return dp[start][end];
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            dp[i][j] = -1000001;
        }
    }
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&s[i]);
    printf("%d\n", f (0, n - 1));
    return 0;
}