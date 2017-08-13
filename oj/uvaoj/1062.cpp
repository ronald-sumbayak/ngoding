#include <iostream>
#include <vector>
using namespace std;

void process (vector<char> &stack, char a) {
    for (int i = 0; i < stack.size (); i++)
        if (a <= stack[i]) {
            stack[i] = a;
            return;
        }
    
    stack.push_back (a);
}

int main (int argc, char **argv) {
    string input;
    int t = 1;
    
    while (cin >> input) {
        if (input == "end") break;
        
        vector<char> stack;
        for (int i = 0; i < input.length (); i++)
            process (stack, input[i]);
        cout << "Case " << t++ << ": " << stack.size () << endl;
    }
    
    return 0;
}