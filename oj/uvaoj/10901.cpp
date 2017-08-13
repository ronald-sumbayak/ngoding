#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int main (int argc, char **argv) {
    int tc, n, t, m, a;
    char s[11];
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d %d", &n, &t, &m);
        std::queue<pair<int, int> > f, l, r;
    
        for (int i = 0; i < m; i++) {
            scanf ("%d %s", &a, s);
            if (strcmp (s, "left") == 0) l.push (make_pair (a, i));
            else r.push (make_pair (a, i));
        }
    
        bool side = false;
        int time = 0;
        int arrive[m];
    
        while (!l.empty () || !r.empty ()) {
            bool loaded = false;
            
            if (!side) {
                for (int j = 0; j < n && !l.empty (); j++)
                    if (l.front ().first <= time)
                        arrive[l.front ().second] = time+t, l.pop (), loaded = true;
            }
            else {
                for (int j = 0; j < n && !r.empty (); j++)
                    if (r.front ().first <= time)
                        arrive[r.front ().second] = time+t, r.pop (), loaded = true;
            }
            
            if (loaded) {
                side = !side;
                time += t; }
            else {
                int right = r.empty () ? l.front ().first+1 : r.front ().first;
                int left = l.empty () ? r.front ().first+1 : l.front ().first;
                
                if (!side) {
                    if (right < left) {
                        if (right > time) time = right;
                        time += t;
                        side = !side; }
                    else if (left > time) time = left; }
                else {
                    if (left < right) {
                        if (left > time) time = left;
                        time += t;
                        side = !side; }
                    else if (right > time) time = right; }
            }
        }
        
        for (int i = 0; i < m; i++)
            printf ("%d\n", arrive[i]);
        if (tc) putchar ('\n');
    }
    
    return 0;
}