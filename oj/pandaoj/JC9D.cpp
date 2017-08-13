#include <vector>
#include <cstdio>
using namespace std;
pair<int, pair<int, int> > e[120];
int n, m;

vector<int> insert (vector<int> v, pair<int, int> p) {
    v[p.first]++; v[p.second]++;
    return v;
}

int solve (int l, int i, vector<int> v) {
    for (int x = 1; x <= n; x++)
        if (v[x] == 3) return 0;
    int sum = 0;
    for (int x = 1; x <= n; x++)
        sum += v[x];
    if (sum > 2*n-2)
        return 0;
    if (i == m)
        return l;
    int a, b;
    a = solve (l, i+1, v);
    b = solve (l+e[i].first, i+1, insert (v, e[i].second));
    return max (a, b);
}

int main (int argc, char **argv) {
    int a, b, d;
    scanf ("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf ("%d %d %d", &a, &b, &d);
        e[i] = make_pair (d, make_pair (a, b));
    }
    
    printf ("%d\n", solve (0, 0, vector<int> (n+1)));
}