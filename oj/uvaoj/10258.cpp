#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct team {
    int id, solved, penalty;
    bool tried;
} Team;

void calculate (vector<Team>& ranking, int score[][11], bool ac[][11]) {
    for (int i = 1; i < 101; i++) {
        ranking[i].id = i;
        for (int j = 1; j < 11; j++) {
            if (ac[i][j]) {
                ranking[i].solved++;
                ranking[i].penalty += score[i][j];
            }
        }
    }
}

bool compare (Team a, Team b) {
    if (a.solved > b.solved) return true;
    if (b.solved > a.solved) return false;
    if (a.penalty < b.penalty) return true;
    if (a.penalty > b.penalty) return false;
    return a.id < b.id;
}

int main (int argc, char **argv) {
    string input;
    int tc, c, p, t;
    char s;
    getline (cin, input);
    sscanf (input.c_str (), "%d", &tc);
    getline (cin, input);
    
    while (tc--) {
        int score[101][11]={};
        bool ac[101][11]={};
        vector<Team> teams (101);
        
        while (getline (cin, input)) {
            if (input.empty ()) break;
            sscanf (input.c_str (), "%d %d %d %c", &c, &p, &t, &s);
            
            teams[c].tried = true;
            if (!ac[c][p]) {
                if (s == 'C') score[c][p] += t, ac[c][p] = true;
                else if (s == 'I') score[c][p] += 20;
            }
        }
        
        calculate (teams, score, ac);
        sort (teams.begin (), teams.end (), compare);
        for (int i = 0; i < 101; i++)
            if (teams[i].tried)
                printf ("%d %d %d\n", teams[i].id, teams[i].solved, teams[i].penalty);
        
        if (tc) printf ("\n");
    }
}