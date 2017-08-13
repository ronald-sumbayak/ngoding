#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int scan (int &numb) {
    scanf ("%d", &numb);
    return numb;
}

    int main (int argc, char **argv) {
        int n, i, a;
        while (scanf ("%d", &n) && n) {
            while (true) {
                vector<int> t (n);
                stack<int> s;
                
                if (scan (t[0]) == 0)
                    break;
                for (int i = 1; i < n; i++)
                    scan (t[i]);
                
                i=1, a=0;
                while (a < n && i <= n)
                    if (i == t[a]) a++, i++;
                    else if (!s.empty () && t[a] == s.top ()) s.pop (), a++;
                    else s.push (i), i++;
                
                while (a < n && t[a] == s.top ())
                    a++, s.pop ();
                if (a == n) printf ("Yes\n");
                else printf ("No\n");
            }
            printf ("\n");
        }
        return 0;
    }