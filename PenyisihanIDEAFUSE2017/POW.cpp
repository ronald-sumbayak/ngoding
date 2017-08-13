#include <bits/stdc++.h>

using namespace std;

string convert(long double myLongDouble) {
    stringstream blah;
    blah << fixed;
    blah << setprecision (100);
    blah << myLongDouble;
       
    return blah.str();
}

int main (int argc, char **argv) {
    cout << fixed;
    cout << setprecision (100);
    int tc, n, x;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &n, &x);
        cout << n << ends << x << endl;
        long double res = n/pow (4.0, 10.0);
        string s = to_string (res);
        int i = s.length () - 1;
        while (s[i] == '0') i--;
        cout << s[i-4] << endl;
        cout << "dsds";
    }
}