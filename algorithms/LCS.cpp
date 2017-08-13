#include <iostream>
using namespace std;

int lcs (string a, string b) {
    int *prev = new int[b.length ()+1] ();
    int *now = new int[b.length ()+1] ();
    
    for (int i = 1; i <= a.length (); i++) {
        swap (now, prev);
        for (int j = 1; j <= b.length (); j++)
            if (a[i-1] == b[j-1])
                now[j] = prev[j-1] + 1;
            else
                now[j] = max (prev[j], now[j-1]);
    }
    
    return now[b.length ()];
}