#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <climits>

using namespace std;

class coor {
public:
    int x, y;
    coor (int x, int y) {
        this->x = x;
        this->y = y;
    }
};

pair<string, coor> get () {
    string name;
    int x, y;
    cin >> name >> x >> y;
    return make_pair (name, coor (x, y));
}

int manhattan (coor a, coor b) {
    return abs (b.x-a.x) + abs (b.y-a.y);
}


int main (int argc, char **argv) {
    int tc, n, m, ix, iy, dx, dy;
    scanf ("%d", &tc);
    
    for (int t = 1; t <= tc; t++) {
        scanf ("%d %d", &n, &m);
        
        vector<pair<string, coor> > dr;
        for (int i = 0; i < n; i++)
            dr.push_back (get ());
        
        printf ("Case #%d:\n", t);
        for (int i = 0; i < m; i++) {
            scanf ("%d %d %d %d", &ix, &iy, &dx, &dy);
            coor pa (ix, iy);
            
            int nearest = INT_MAX, nx, ny, di;
            string taken;
            for (int j = 0; j < dr.size (); j++) {
                int man = manhattan (dr[j].second, pa);
                if (man < nearest) {
                    nearest = man;
                    nx = dr[j].second.x;
                    ny = dr[j].second.y;
                    taken = dr[j].first;
                    di = j;
                }
                else if (man == nearest && dr[j].first < taken) {
                    nx = dr[j].second.x;
                    ny = dr[j].second.y;
                    taken = dr[j].first;
                    di = j;
                }
            }
            
            dr[di].second.x = dx;
            dr[di].second.y = dy;
            cout << taken << endl;
        }
    }
}