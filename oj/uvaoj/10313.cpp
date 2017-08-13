#include <cstdio>

long long dp[303][303]={};

void calculate () {
    for (int i = 0; i < 303; i++) {
        dp[0][i] = 0;
        dp[i][0] = 1;
    }
    
    for (int i = 1; i < 303; i++) {
        for (int j = 1; j < 303; j++) {
            if (j < i) dp[i][j] += (dp[i-1][j]);
            else dp[i][j] += (dp[i-1][j] + dp[i][j-i]);
        }
    }
}

long long lookup[303][303];

long long topdown (int i, int j) {
    if (j < 0) return 0;
    if (j == 0) return 1;
    if (i == 0) return 0;
    if (lookup[i][j] == 0) {
        lookup[i][j] = topdown (i-1, j) + topdown (i, j-i);
    }
    return lookup[i][j];
}

int main () {
    char input[100];
    int n, a, b, c;
    long long answer;
    calculate ();
    
    while (gets (input)) {
        n = sscanf (input, "%d %d %d", &a, &b, &c);
        /*
        switch (n) {
            case 1: answer = dp[a][a]; break;
            case 2:
                if (b > a) b = a;
                answer = dp[b][a]; break;
            case 3:
                if (c < b) {
                    answer = 0;
                    break;
                }
                if (c > a) c = a;
                if (b == 0) b = 1;
                else answer = dp[c][a] - dp[b-1][a];
                break;
            default: break;
        }
         */
    
    
        switch (n) {
            case 1: answer = topdown (a, a); break;
            case 2:
                if (b > a) b = a;
                answer = topdown (b, a); break;
            case 3:
                if (c < b) {
                    answer = 0;
                    break;
                }
                if (c > a) c = a;
                if (b == 0) b = 1;
                else answer = topdown (c, a) - topdown (b-1, a);
                break;
            default: break;
        }
        
        printf ("%lld\n", answer);
    }
}