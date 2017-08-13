#include <cstdio>
#include <queue>
using namespace std;

class coor {
public:
    int x, y, d;
    
    coor (int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    coor (int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
};

coor dir[4] = {coor (0, -1), coor (1, 0), coor (0, 1), coor (-1, 0)};
char mall[101][101];
int r, c;

bool valid (int x, int y) {
    if (x < 0 || x == c || y < 0 || y == r)
        return false;
    if (mall[y][x] == 's')
        return false;
    return mall[y][x] != '#';
}

int main (int argc, char **argv) {
    int m, cy, cx;
    scanf ("%d", &m);
    
    while (m--) {
        scanf ("%d %d", &r, &c);
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf ("%c", &mall[i][j]);
                if (mall[i][j] == 'C')
                    cy = i, cx = j;
            }
        }
        
        std::queue<coor> q;
        q.push (coor (cx, cy, 0));
        int max, sum=0;
        
        while (!q.empty ()) {
            coor now = q.front ();
            q.pop ();
            
            if (mall[now.y][now.x] == 's') {
                sum += (2 * now.d);
                sum += 60;
                max = now.d; }
            
            for (int i = 0; i < 4; i++) {
                coor cand (now.x+dir[i].x, now.y+dir[i].y, now.d+1);
                if (valid (cand.x, cand.y)) {
                    q.push (cand);
                    if (mall[cand.y][cand.x] == 'S')
                        mall[cand.y][cand.x] = 's';
                    else
                        mall[cand.y][cand.x] = '#';
                }
            }
        }
        
        printf ("%d\n", sum - max);
    }
}