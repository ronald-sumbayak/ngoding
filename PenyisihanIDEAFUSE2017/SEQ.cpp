#include <cstdio>
#include <map>
using namespace std;

int main (int argc, char **argv) {
    
    int tc, n;
    scanf ("%d", &tc);
    
    for (int t = 1; t <= tc; t++) {
        scanf ("%d", &n);
        
        int s1[n];
        for (int i = 0; i < n; i++)
            scanf ("%d", &s1[i]);
        
        std::map<int, int> s2;
        int res = s2[s1[0]] = 1;
        
        for (int i = 1; i < n; i++) {
            s2[s1[i]] = max (s2[s1[i]], 1 + max (s2[s1[i] - 1], s2[s1[i] + 1]));
            res = std::max (res, s2[s1[i]]);
        }
        
        printf ("Case #%d: %d\n", t, res);
    }
    
    return 0;
}

