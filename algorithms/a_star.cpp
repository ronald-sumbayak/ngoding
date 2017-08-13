#include <bits/stdc++.h>
#define forij(i,j) for(int i=0;i<3;i++) for(int j=0;j<3;j++)
using namespace std;

class Coor {
public:
    Coor (int x, int y) {
        this->x = x;
        this->y = y;
    }
    
    int x, y;
    Coor () {}
    static bool equal (Coor a, Coor b) { return (a.x == b.x) && (a.y == b.y); }
    static Coor sum (Coor a, Coor b) { return Coor (a.x + b.x, a.y + b.y); }
};

class State {
public:
    static int goal[3][3];
    State *parent;
    int board[3][3];
    Coor c;
    int g, h;
    
    State (Coor c, int board[3][3]) {
        parent = NULL;
        this->c = c;
        copy_board (board);
        g = 0;
        heuristic ();
    }
    
    State (State *parent, Coor c) {
        this->parent = parent;
        this->c = c;
        copy_board (parent->board);
        swap (board[c.y][c.x], board[parent->c.y][parent->c.x]);
        g = parent->g + 1;
        heuristic ();
    }
    
    void copy_board (int board[3][3]) {
        forij (i, j)
            this->board[i][j] = board[i][j];
    }
    
    void heuristic () {
        h = 0;
        for (int i = 1; i < 9; i++)
            if (!Coor::equal (getcoor (board, i), getcoor (goal, i)))
                h++;
    }
    
    static Coor getcoor (int board[3][3], int x) {
        forij (i, j)
            if (board[i][j] == x)
                return Coor (j, i);
        return Coor ();
    }
    
    static void setgoal (int g[3][3]) {
        forij (i, j)
            goal[i][j] = g[i][j];
    }
    
    void print () {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
            cout << board[i][j] << ends;
            cout << endl;
        }
    }
    
    int cost () const { return g + h; }
};

struct comp {
    bool operator () (State *a, State *b) {
        return a->cost () > b->cost ();
    }
};

int State::goal[3][3];
Coor m[4] = {Coor (-1, 0), Coor (0, 1), Coor (1, 0), Coor (0, -1)};

bool inbound (Coor c) {
    return (0 <= c.x && c.x < 3) && (0 <= c.y && c.y < 3);
}

void printPath (State *a) {
    if (a == NULL) return;
    printPath (a->parent);
    a->print ();
    cout << endl;
}

State *A_star (State *initial) {
    priority_queue<State*, vector<State*>, comp> q;
    q.push (initial);
    
    while (!q.empty ()) {
        State *a = q.top ();
        q.pop ();
        if (a->h == 0) return a;
        
        for (int i = 0; i < 4; i++) {
            if (!inbound (Coor::sum (a->c, m[i]))) continue;
            if (a->parent != NULL && Coor::equal (a->parent->c, Coor::sum (a->c, m[i]))) continue;
            State *child = new State (a, Coor::sum (a->c, m[i]));
            q.push (child);
        }
    }
    return NULL;
}

int main (int argc, char **argv) {
    int initial[3][3] = {
        {0, 1, 2},
        {4, 5, 3},
        {7, 8, 6}
    };
    
    int goal[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    State::setgoal (goal);
    State *final = A_star (new State (State::getcoor (initial, 0), initial));
    printPath (final);
    return 0;
}