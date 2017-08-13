#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

#define voi std::vector<int>
#define vovoi std::vector<voi >
#define vovovoi std::vector<vovoi >
int getNumb ();
vovovoi buildLampTable ();

int main () {
    int tc, n, c, a, b;
    scanf ("%d", &tc);
    vovovoi table = buildLampTable ();
    
    for (int t = 1; t <= tc; t++) {
        std::vector<int> x, y;
        scanf ("%d %d", &n, &c);
        scanf ("%d", &a);
        for (int i = 0; i < a; i++) x.push_back (getNumb ());
        scanf ("%d", &b);
        for (int i = 0; i < b; i++) y.push_back (getNumb ());
        
        c--;
        c = std::min (c, 2);
        
        std::set<std::string> answers;
        printf ("Kasus %d:\n", t);
        
        for (int i = 0; i < table[c].size (); i++) {
            bool valid = true;
            for (int j = 0; j < x.size (); j++) if (table[c][i][x[j]%6] == 0) valid = false, j = x.size ();
            if (!valid) continue;
            for (int j = 0; j < y.size (); j++) if (table[c][i][y[j]%6] == 1) valid = false, j = y.size ();
            if (!valid) continue;
            
            std::string build = "";
            for (int j = 0; j < n; j++) build += (table[c][i][j%6] + '0');
            if (c < 3 && !answers.insert (build).second) continue;
            std::cout << build << std::endl;
        }
    }
    
    return 0;
}

vovovoi buildLampTable () {
    int table[8][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };
    
    int member[3][8] = {
        {8, 2, 3, 5, 0, 0, 0, 0},
        {8, 1, 2, 4, 5, 6, 7, 0},
        {8, 1, 2, 3, 4, 5, 6, 7}
    };
    
    vovovoi result;
    
    for (int i = 0; i < 3; i++) {
        vovoi outer;
        for (int j = 0; j < 8; j++) {
            voi inner;
            for (int k = 0; k < 6 && member[i][j]; k++) inner.push_back (table[member[i][j] % 8][k]);
            if (!inner.empty ()) outer.push_back (inner);
        }
        result.push_back (outer);
    }
    
    return result;
}

int getNumb () {
    int i;
    scanf ("%d", &i);
    return i - 1;
}