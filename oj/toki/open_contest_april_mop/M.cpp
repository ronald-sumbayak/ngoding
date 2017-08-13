#include <iostream>
using namespace std;

int rima (string a, string b) {
    for (int i = 0; ; i++) {
        if (a.length ()-1-i < 0)
            return i;
        if (b.length ()-1-i < 0)
            return i;
        if (a[a.length ()-1-i] != b[b.length ()-1-i])
            return i;
    }
}

void last (string s, int len) {
    for (int i = s.length ()-len; i < s.length (); i++)
        cout << s[i];
}

int main () {
    string b[4];
    for (int i = 0; i < 4; i++)
        getline (cin, b[i]);
    
    int l, r, m;
    l = rima (b[0], b[1]);
    r = rima (b[0], b[2]);
    m = rima (b[1], b[2]);
    
    if (m == l && m == r) 
        last (b[0], l);
    else if (m > l && m > r)
        last (b[0], m);
    else if (l > r)
        last (b[2], l);
    else
        last (b[1], r);
}