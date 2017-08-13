#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
string in, out;

stack<char> push (stack<char> st, char ins) {
    st.push (ins);
    return st;
}

stack<char> pop (stack<char> st) {
    st.pop ();
    return st;
}

stack<char> create (string s) {
    stack<char> st;
    for (int i = s.length ()-1; i >= 0; i--)
        st.push (s[i]);
    return st;
}

void solve (string path, int i, stack<char> s, stack<char> tmp) {
    if (path.length () == out.length ()*2) {
        if (i == out.length ()) 
            for (int x = 0; x < path.length (); x++)
                printf ("%c%c", path[x], x+1 < path.length () ? ' ' : '\n');
        return;
    }
    if (!tmp.empty ())
        solve (path+"i", i, push (s, tmp.top ()), pop (tmp));
    if (!s.empty ())
        if (out[i] == s.top ())
            solve (path+"o", i+1, pop (s), tmp);
        // else
           // solve (path+"o", i, pop (s), push (tmp, s.top ()));
}

int main (int argc, char **argv) {
    ios::sync_with_stdio (false);
    while (cin >> in >> out) {
        printf ("[\n");
        if (in.length () == out.length ())
            solve ("", 0, stack<char> (), create (in));
        printf ("]\n");
    }
}