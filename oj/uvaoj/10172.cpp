#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int get () {
    int n;
    scanf ("%d", &n);
    return n;
}

int main (int argc, char **argv) {
    int set, n, s, q, qi;
    scanf ("%d", &set);
    
    while (set--) {
        scanf ("%d %d %d", &n, &s, &q);
        
        vector<queue<int> > st ((unsigned int) (n+1));
        stack<int> car;
        int time=0, now=1;
        
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &qi);
            while (qi--) st[i].push (get ());
        }
        
        while (true) {
            while (!car.empty () && (car.top () == now || st[now].size () < q)) {
                if (car.top () != now)
                    st[now].push (car.top ());
                car.pop ();
                time++;
            }
            
            while (car.size () < s && !st[now].empty ()) {
                car.push (st[now].front ());
                st[now].pop ();
                time++;
            }
            
            bool done = car.empty ();
            for (int i = 1; i <= n; i++) done &= st[i].empty ();
            if (done) break;
            
            time += 2;
            now = (now % n) + 1;
        }
        
        printf ("%d\n", time);
    }
    
    return 0;
}