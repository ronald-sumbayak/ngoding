#include <cstdio>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

typedef struct node {
    string name;
    struct node *parent = NULL;
} Fam;

map<string, Fam*> at;

void findpath (Fam *n, stack<string> &s) {
    while (n != NULL) {
        s.push (n->name);
        n = n->parent;
    }
}

string findlca (stack<string> &a, stack<string> &b) {
    string anc = a.top ();
    while (!a.empty () && !b.empty ()) {
        if (a.top () != b.top ()) {
            return anc;
        }
        anc = a.top ();
        a.pop ();
        b.pop ();
    }
    return anc;
}

void printpath (stack<string> s) {
    while (!s.empty ()) {
        cout << s.top ();
        if (s.size () > 1) cout << "->";
        s.pop ();
    }
}

int main (int argc, char **argv) {
    string name, father;
    int n, t;
    cin >> n >> t;
    
    for (int i = 1; i < n; i++) {
        cin >> name >> father;
        
        if (at[father] == NULL) {
            at[father] = new Fam ();
            at[father]->name = father;
        }
        
        Fam *f = new Fam ();
        f->name = name;
        f->parent = at[father];
        at[name] = f;
    }
    
    //cout << ": " << at["Abdul"]->parent->name << endl;
    
    for (int i = 1; i <= t; i++) {
        cin >> name;
        stack<string> sa, sb;
        findpath (at[name], sa);
        findpath (at["Blangkon"], sb);
        string anc = findlca (sa, sb);
    
        cout << "Case #" << i << ":" << endl;
        if (sb.empty ()) cout << anc;
        else cout << anc << "->";
        printpath (sb);
        cout << endl;
        if (sa.empty ()) cout << anc;
        else cout << anc << "->";
        printpath (sa);
        cout << endl;
        if (i != t) cout << endl;
    }
}