#include <algorithm>
#include <iostream>
using namespace std;

int main (int arg, char **argv) {
    string input;
    while (cin >> input) {
        if (input == "#") break;
        if (next_permutation (input.begin (), input.end ())) cout << input << endl;
        else cout << "No Successor" << endl;
    }
}