#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

#define poii pair<long long, long long>

using namespace std;

int main (int argc, char **argv) {
    long long tc, n, k, x, m, s, a, b, c, u, v, w;
    scanf ("%lld", &tc);
    
    while (tc--) {
        scanf ("%lld %lld %lld %lld %lld", &n, &k, &x, &m, &s);
        vector<vector<poii > > adj ((unsigned int) (n+1));
        
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == j) continue;
                adj[i].push_back (make_pair (x, j));
                adj[j].push_back (make_pair (x, i));
            }
        }
        
        for (int i = 0; i < m; i++) {
            scanf ("%lld %lld %lld", &a, &b, &c);
            adj[a].push_back (make_pair (c, b));
            adj[b].push_back (make_pair (c, a));
        }
        
        priority_queue<poii, vector<poii>, greater<poii> > p;
        vector<long long> dist ((unsigned int) (n+1), LONG_LONG_MAX);
        p.push (make_pair (0, s));
        dist[s] = 0;
        
        while (!p.empty ()) {
            poii f = p.top ();
            p.pop ();
            u = f.second;
            
            for (int i = 0; i < adj[u].size (); i++) {
                v = adj[u][i].second;
                w = adj[u][i].first;
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    p.push (make_pair (dist[v], v));
                }
            }
        }
        
        for (int i = 1; i <= n; i++)
            printf ("%lld ", dist[i]);
        printf ("\n");
    }
}