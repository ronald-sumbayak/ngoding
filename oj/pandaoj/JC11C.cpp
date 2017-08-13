#include <cstdio>
#include <algorithm>

int scan () {
    int n;
    scanf ("%d", &n);
    return n;
}

int main (int argc, char **argv) {
    int n;
    scanf ("%d", &n);
    
    int c[n], sum=0;
    for (int i = 0; i < n; i++)
        sum += c[i] = scan ();
    
    int dp[sum+1], gr[sum+1];
    int f = 0;
    
    sum = std::min (sum, 3*c[n-1]);
    for (int i = 0; i <= sum+1; i++)
        dp[i] = gr[i] = i;
    
    for (int i = 0; i <= sum; i++) {
        for (int j = 1; j < n; j++) {
            if (c[j] <= i) {
                dp[i] = std::min (dp[i], dp[i-c[j]] + 1);
                gr[i] = gr[i-c[j]] + 1;
            }
        }
        
        if (dp[i] != gr[i]) {
            f = i; break;
        }
    }
    
    if (f == 0) printf ("YES");
    else printf ("NO %d", f);
}