#include <iostream>
#include <queue>
using namespace std;

int main (int argc, char **argv) {
    int tc, l, m, c;
    string side;
    cin >> tc;
    
    while (tc--) {
        cin >> l >> m;
        l *= 100;
        
        queue<int> left, right;
        for (int i = 0; i < m; i++) {
            cin >> c >> side;
            if (side == "left") left.push (c);
            else right.push (c);
        }
        
        int now = 0;
        while (!left.empty () || !right.empty ()) {
            int ferry = 0;
            
            if (now%2 == 0)
                while (!left.empty ())
                    if (ferry + left.front () <= l) {
                        ferry = ferry + left.front ();
                        left.pop ();
                    }
                    else break;
            else
                while (!right.empty ())
                    if (ferry + right.front () <= l) {
                        ferry = ferry + right.front ();
                        right.pop ();
                    }
                    else break;
            now++;
        }
        
        cout << now << endl;
    }
    
    return 0;
}