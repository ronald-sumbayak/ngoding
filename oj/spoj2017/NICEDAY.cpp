#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int getNumb () {
    int r=0;
    int c;
    
    while (true) {
        c = getchar_unlocked ();
        if (c == ' ' || c == '\n') continue;
        else break;
    }
    
    if (c != '-') r = r + c - '0';
    
    while (true) {
        c = getchar_unlocked ();
        if (c >= '0' && c <= '9') r = 10 * r + c -'0';
        else break;
    }
    
    return r;
}

class score {
public:
    int a, b, c, total;
    
    score () {
        a = getNumb ();
        b = getNumb ();
        c = getNumb ();
        total = a + b + c;
    }
    
    bool excell (score other) {
        return a >= other.a && b >= other.b && c >= other.c;
    }
};

bool comparator (score a, score b) {
    return a.total < b.total;
}

int main (int argc, char **argv) {
    int tc, n;
    tc = getNumb ();
    
    while (tc--) {
        n = getNumb ();
    
        vector<score> contestants, excellent;
        for (int i = 0; i < n; i++) contestants.push_back (score ());
        sort (contestants.begin (), contestants.end (), comparator);
        
        for (int i = 0; i < n; i++) {
            bool dominant = true;
            
            for (int j = 0; j < excellent.size (); j++) {
                if (contestants[i].excell (excellent[j])) {
                    dominant = false;
                    break;
                }
            }
            
            if (dominant)
                excellent.push_back (contestants[i]);
        }
        
        printf ("%lu\n", excellent.size ());
    }
    
    return 0;
}