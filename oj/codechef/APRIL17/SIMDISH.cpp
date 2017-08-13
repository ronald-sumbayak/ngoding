#include <iostream>
#include <set>
using namespace std;

string get () {
    string in;
    cin >> in;
    return in;
}

int main (int argc, char **argv) {
    int tc;
    cin >> tc;
    
    while (tc--) {
        set<string> ing;
        for (int i = 0; i < 4; i++)
            ing.insert (get ());
        int same = 0;
        for (int i = 0; i < 4; i++)
            if (!ing.insert (get ()).second)
                same++;
        if (same > 1) cout << "similar" << endl;
        else cout << "dissimilar" << endl;
    }
}