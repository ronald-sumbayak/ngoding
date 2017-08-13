#include <cstdio>
#include <queue>
using namespace std;

int getNumb () {
    int r=0;
    int c;
    
    while (true) {
        c = getchar_unlocked ();
        if (c == ' ' || c == '\n') continue;
        else break;
    }
    
    if (c != '-') r = r + c - '0';
    
    while (true) {
        c = getchar_unlocked ();
        if (c >= '0' && c <= '9') r = 10 * r + c -'0';
        else break;
    }
    
    return r;
}

int main (int argc, char **argv) {
    int n;
    n = getNumb ();
    queue<pair<int, int> > tasks;
    long long int elapsed[n];
    
    for (int i = 0; i < n; i++) tasks.push (make_pair (i, getNumb ()));
    long long int time = 0;
    while (!tasks.empty ()) {
        pair<int, int> head = tasks.front ();
        head.second--;
        time++;
        if (head.second == 0) elapsed[head.first] = time;
        else tasks.push (head);
        tasks.pop ();
    }
    
    for (int i = 0; i < n; i++) printf ("%lld\n", elapsed[i]);
    return 0;
}