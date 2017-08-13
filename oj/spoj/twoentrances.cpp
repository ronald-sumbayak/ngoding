#include <algorithm> 
#include <iostream> 
#include <cstring>
#include <cstdio>

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forn(i, n) forint(i, 0, (n)-1)
using namespace std;
 
const int MAXN = 3030;
const long long MOD = 1000000007;

long long binom[MAXN][MAXN];
int g[MAXN], g_lnk[MAXN*2], g_nxt[MAXN*2];
int n;

int pa[MAXN], pn;
int pre[MAXN];

void dfs (int x, int fa) {
    pre[x] = fa;
    for (int e = g[x]; e != 0; e = g_nxt[e]) {
        if (g_lnk[e] != fa) {
            dfs (g_lnk[e], x);
        }
    }
}

void find_path (int s1, int s2) {
    dfs (s1, 0);
    pn = 0;
    
    for (int x = s2; x != 0; x = pre[x]) {
        pa[++pn] = x;
    }
    
    reverse (pa+1, pa+pn+1);
}

bool vis[MAXN];
long long u[MAXN];
int sz[MAXN];
int sum_sz[MAXN];

void go (int x) {
    u[x] = 1, sz[x] = 0;
    for (int e=g[x], y; e; e=g_nxt[e])
        if (!vis[y = g_lnk[e]]) {
            vis[y] = true;
            go (y);
            u[x] = (u[x] * u[y] % MOD * binom[sz[x]+sz[y]][sz[y]]) % MOD;
            sz[x] += sz[y];
        }
    
    sz[x]++;
}

class TwoEntrances {
public:
    void init () {
        memset (binom, 0, sizeof (binom));
        for (int i = 0; i < MAXN; i++) binom[i][0] = binom[i][i] = 1;
        for (int i = 0; i < MAXN; i++) {
            for (int j = 1; j < i; j++) {
                binom[i][j] = (binom[i-1][j-1] + binom[i-1][j]) % MOD;
            }
        }
    }
    
    int count(vector<int> a, vector<int> b, int s1, int s2) {
        init ();
        memset (g, 0, sizeof (g));
        n = (int) a.size () + 1;
        
        forn (i, n-1) {
            int x=a[(size_t) i], y=b[(size_t) i]; ++x, ++y;
            static int e=0;
            g_lnk[++e]=y, g_nxt[e]=g[x], g[x]=e;
            g_lnk[++e]=x, g_nxt[e]=g[y], g[y]=e;
        }
//        init ();
//        memset (g, 0, sizeof(g));
//        n = (int) a.size () + 1;
//        
//        for (int i = 0; i < n; i++) {
//            int x = a[(size_t) i];
//            int y = b[(size_t) i];
//            x++, y++;
//            
//            static int e = 0;
//            g_lnk[++e] = y, g_nxt[e] = g[x], g[x] = e;
//            g_lnk[++e] = x, g_nxt[e] = g[y], g[y] = e;
//        }
        
        s1++, s2++;
        find_path (s1, s2);
        
        memset (vis, false, sizeof (vis));
        for (int i = 1; i <= pn; i++) vis[pa[i]] = true;
        for (int i = 1; i <= pn; i++) go (pa[i]);
        sum_sz[0] = 0;
        for (int i = 1; i <= pn; i++) sum_sz[i] = sum_sz[i-1] + sz[pa[i]];
        
        static long long f[MAXN][MAXN];
        memset (f, 0, sizeof (f));
        for (int i = 1; i <= pn; i++) f[i][i] = u[pa[i]];
        for (int i = pn; i >= 1; i--) {
            for (int j = i; j <= pn; j++) {
                long long tmp;
                if (i > 1) {
                    tmp = f[i][j];
                    tmp *= u[pa[i-1]];
                    tmp %= MOD;
                    
                    int sz1 = sum_sz[j] - sum_sz[i-1];
                    int sz2 = sz[pa[i-1]] - 1;
                    
                    tmp *= binom[sz1+sz2][sz1];
                    tmp %= MOD;
                    
                    f[i-1][j] += tmp;
                    f[i-1][j] %= MOD;
                }
                
                if (j < n) {
                    tmp = f[i][j];
                    tmp *= u[pa[j+1]];
                    tmp %= MOD;
                    
                    int sz1 = sum_sz[j] - sum_sz[i-1];
                    int sz2 = sz[pa[j+1]] - 1;
                    tmp *= binom[sz1+sz2][sz1];
                    tmp %= MOD;
                    f[i][j+1] += tmp;
                    f[i][j+1] %= MOD;
                }
            }
        }
        
        long long ans = f[1][pn];
        return int (ans);
    }
};

int main () {
    int n, input, s1, s2;
    vector<int> a, b;
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf ("%d", &input);
        a.push_back (input);
    }
    
    for (int i = 0; i < n; i++) {
        scanf ("%d", &input);
        b.push_back (input);
    }
    
    scanf ("%d %d", &s1, &s2);
    
    TwoEntrances twoEntrances;
    printf ("%d\n", twoEntrances.count (a, b, s1, s2));
}