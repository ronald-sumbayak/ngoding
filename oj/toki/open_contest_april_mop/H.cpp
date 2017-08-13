#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;
string s[2000];
int r, c;
int m[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid (int y, int x) {
    if (y < 0 || y == r) return false;
    if (x < 0 || x == c) return false;
    return s[y][x] == -37 || s[y][x] == -80;
}

int walk (int i, int j) {
    queue<pair<int, int> > q;
    q.push (make_pair (i, j));
    if (s[i][j] == -37) s[i][j] = 37;
    else s[i][j] = 80;
    int width = 0;
    
    while (!q.empty ()) {
        pair<int, int> f = q.front ();
        q.pop ();
        if (s[f.first][f.second] == 37)
            width++;
        
        for (int k = 0; k < 4; k++) {
            int y, x;
            y = f.first + m[k][0];
            x = f.second + m[k][1];
            if (!valid (y, x)) continue;
            q.push (make_pair (y, x));
            if (s[y][x] == -37) s[y][x] = 37;
            else s[y][x] = 80;
        }
    }
    
    return width;
}

int main () {
    cin >> r >> c;
    getline (cin, s[0]);
    for (int i = 0; i < r; i++)
        getline (cin, s[i]);
    
    int ma = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == -37) {
                int w = walk (i, j);
                if (w > ma) ma = w;
            }
        }
    }
    
    cout << ma;
//    for (int i = 0; i < r; i++)
//        puts (s[i]);
}