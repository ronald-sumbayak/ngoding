#include <cstdio>
#include <map>
#include <vector>

using namespace std;

vector<pair<int, int> > bs (202);
map<int, int> psg;

int main (int argc, char **argv) {
    int T, Q, B, a, b;
    scanf ("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        scanf ("%d %d", &Q, &B);
        
        for (int i = 0; i < Q; i++) {
            scanf ("%d %d", &a, &b);
            psg[a] = b;
            psg[b] = a;
        }
        
        for (int i = 0; i < B; i++) 
            scanf ("%d %d", &bs[i].first, &bs[i].second);
        
        for (int i = 0; i < B; i++) {
            
        }
    }
}