#include <vector>
#include <climits>
#include <cstdio>
#include <algorithm>

using namespace std;

int main (int argc, char **argv) {
    int n, s, f;
    scanf ("%d", &n);
    
    vector<pair<int, int> > sch;
    sch.push_back (make_pair (0, 0));
    
    for (int i = 0; i < n; i++) {
        scanf ("%d %d", &s, &f);
        sch.push_back (make_pair (f, s));
    }
    
    sort (sch.begin (), sch.end ());
    sch.push_back (make_pair (INT_MAX, INT_MAX));
    int dp[n+2][n+2]={};
    
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j+i <= n+1; j++)
            for (int k = j+1; k < j+i; k++)
                if (sch[j].first < sch[k].second && sch[k].first < sch[j+i].second)
                    dp[j][j+i] = max (dp[j][j+i], dp[j][k]+dp[k][j+i]+1);
    
    printf ("%d\n", dp[0][n+1]);
}