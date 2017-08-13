#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool is_common_prefix (string a, string b, int length) {
    if (length > b.length ()) return false;
    if (a.length () < length) return false;
    return equal (b.begin (), b.begin ()+length, a.begin ());
}

int main (int argc, char **argv) {
    string word, prev;
    int tc;
    scanf ("%d", &tc);
    getline (cin, prev);
    getline (cin, prev);
    
    while (tc--) {
        prev = "";
        int space = 0;
        
        while (getline (cin, word) && !word.empty ()) {
            space++;
            while (!is_common_prefix (word, prev, space) && space) space--;
            for (int i = 0; i < space; i++) printf (" ");
            printf ("%s\n", word.c_str ());
            prev = word;
        }
        
        if (tc) printf ("\n");
    }
    
    return 0;
}