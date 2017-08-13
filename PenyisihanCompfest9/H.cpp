#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

int main (int argc, char** argv) {
    string str;
    int tc, n, max;
    cin >> tc;
    
    while (tc--) {
        map<char, int> m;
        cin >> n;
        
        cin >> str;
        max = 0;
        for (char c : str) {
            m[c]++;
            if (m[c] > max) max = m[c];
        }
        
        std::cout << str.length () - max << endl;
    }
    
    return 0;
}