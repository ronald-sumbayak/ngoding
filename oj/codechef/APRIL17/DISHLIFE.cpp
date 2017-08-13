#include <map>
#include <cstdio>

int main (int argc, char **argv) {
    int tc, n, k, p, a;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &n, &k);
        
        std::map<int, int> ing;
        bool some = false;
        
        for (int i = 0; i < n; i++) {
            scanf ("%d", &p);
            int skip = true;
            
            while (p--) {
                scanf ("%d", &a);
                if (ing[a] == 0)
                    skip = false;
                ing[a]++;
            }
            
            if (skip) some = true;
        }
        
        bool poss = true;
        for (int i = 1; i <= k; i++)
            if (ing[i] == 0)
                poss = false;
        
        if (!poss) printf ("sad\n");
        else if (some) printf ("some\n");
        else printf ("all\n");
    }
}