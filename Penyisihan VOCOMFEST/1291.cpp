#include<bits/stdc++.h>
using namespace std;
int maxcnt=0;
vector<pair<int,pair<int,int> > > vec;
int meetnum,money;
int main (int argc, char **argv) {
    int tc, n, m, a, b, c;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &n, &m);
        
        int days = 0;
        vector<pair<int, pair<int, int> > > me;
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d", &a, &b, &c);
            me.push_back (make_pair (c, make_pair (a, b)));
            days = max (days, b);
        }
        
        int dp[days+1];
        int bm[days+1][n+1];
        dp[0] = 0;
        
        for (int i = 1; i <= days; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < n; j++)
                bm[i][j] = bm[i-1][j];
            for (int j = 0; j < n; j++) {
                if (me[j].second.second == i) {
                    if (dp[me[j].second.first-1]+me[j].first < dp[i]) {
                        for (int k = 0; k < n; k++)
                            bm[i][k] = bm[me[j].second.first-1][k];
                        bm[i][j] = 1;
                    }
                }
            }
            
            if (dp[i] == INT_MAX) dp[i] = dp[i-1];
        }
        
        int count = 0;
        for (int i = 0; i <= days; i++) {
            printf ("%d ", dp[i]);
            count += bm[days][i];
        }
        printf ("\n");
        printf ("%d\n", count);
    }
}
