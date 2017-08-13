#include <stdio.h>

int parent[10001];

int find (int u) {
    if (parent[u] == u) return u;
    else return parent[u] = find (parent[u]);
}

int main () {
    int tc;
    scanf ("%d", &tc);
    
    while (tc--) {
        int n, m;
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++) {
            int a, b, u, v;
            scanf ("%d %d", &a, &b);
            u = find (a);
            v = find (b);
            
            if (u != v)  {
                if (u > v) parent[u] = v;
                else parent[v] = u;
            }
        }
        
        int set = 0;
        for (int i = 1; i <= n; i++) if (i == find (i)) set = set + 1;
        if (set == 1) printf ("YES\n");
        else printf ("NO\n");
    }
}