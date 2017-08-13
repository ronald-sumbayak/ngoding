#include <iostream>
using namespace std;

string uncompress (string toUncompress, int repeat=1) {
    size_t first, last;
    first = toUncompress.find_first_of ("[");
    last = toUncompress.find_last_of ("]");
    
    string builder;
    builder = toUncompress.substr (0, first);
    
    if (first != last) {
        string inner;
        inner = toUncompress.substr (first+1, last-first-1);
        inner = uncompress (inner.substr (1), inner[0] - '0');
        builder += inner;
        builder += toUncompress.substr (last+1);
    }
    
    string copy = builder;
    for (int i = 1; i < repeat; i++) builder += copy;
    return builder;
}

int main (int args, char const *argv[]) {
    string input;
    while (cin >> input) cout << uncompress (input) << endl;
}