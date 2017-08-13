#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

list<char> text, broken;

void print (list<char>& text) {
    while (!text.empty ()) {
        printf ("%c", text.front ());
        text.pop_front ();
    }
}

void insert (char c) {
    if (c == '[' || c == ']') {
        text.splice (text.end (), broken);
        if (c == '[') swap (text, broken);
    }
    else
        text.push_back (c);
}

int main (int argc, char const *argv[]) {
    string s;
    while (cin >> s) {
        for (int i = 0; i < s.length (); i++)
            insert (s[i]);
        print (text);
        print (broken);
        printf ("\n");
    }
    return 0;
}