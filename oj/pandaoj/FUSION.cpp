#include<bits/stdc++.h>
using namespace std;

bool issubsequence (string a, string b) {
    int i = 0;
    for (int j = 0; i < a.length () && j < b.length (); j++)
        if (a[i] == b[j]) i++;
    return i == a.length ();
}

int longestsub (string a, string b) {
    for (int i = a.length (); i > 0; i--)
        for (int j = 0; j < a.length ()-i+1; j++)
            if (issubsequence (a.substr (j, i), b))
                return i;
    return 0;
}

int main (int argc, char **argv) {
    int tc, a, b;
    string m, n;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) {
        cin >> a >> b;
        cin >> m;
        cin >> n;
        
        int l = longestsub (m, n);
        cout << "Kasus " << t << ": " << (m.length ()+n.length ())-l << endl;
    }
}