#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;
queue<vector<string> > step;
ofstream output;

string whoWins (vector<string> b) {
    step.push (b);
    
    int player1 = 0, player2 = 0;
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
        if (b[i][j] == 'O') player1++;
        if (b[i][j] == 'X') player2++;
    }
    
    if (player1 > player2+1 || player2 > player1) return "INVALID";
    
    bool win1 = false, win2 = false;
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == 'X' && b[i][1] == 'X' && b[i][2] == 'X') win2 = true;
        if (b[i][0] == 'O' && b[i][1] == 'O' && b[i][2] == 'O') win1 = true;
        if (b[0][i] == 'X' && b[1][i] == 'X' && b[2][i] == 'X') win2 = true;
        if (b[0][i] == 'O' && b[1][i] == 'O' && b[2][i] == 'O') win1 = true;
    }
    
    if (b[0][0] == 'O' && b[1][1] == 'O' && b[2][2] == 'O') win1 = true;
    if (b[0][0] == 'X' && b[1][1] == 'X' && b[2][2] == 'X') win2 = true;
    if (b[2][0] == 'O' && b[1][1] == 'O' && b[0][2] == 'O') win1 = true;
    if (b[2][0] == 'X' && b[1][1] == 'X' && b[0][2] == 'X') win2 = true;
    
    if (win1 && win2) return "INVALID";
    if (win1 && player2 == player1) return "INVALID";
    if (win2 && player1 > player2) return "INVALID";
    
    if (win1) return "FIRST";
    if (win2) return "SECOND";
    if (player1 + player2 == 9) return "DRAW";
    
    bool canWin = false, canDraw = false;
    if (player1 > player2) {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
                if (b[i][j] == '.') {
                    b[i][j] = 'X';
                    string res = whoWins (b);
                    if (res == "DRAW") canDraw = true;
                    if (res == "SECOND") canWin = true;
                    
                    b[i][j] = '.';
                    if (canWin) break;
                }
            }
        if (canWin) return "SECOND";
        if (canDraw) return "DRAW";
        return "FIRST";
    }
    else {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
                if (b[i][j] == '.') {
                    b[i][j] = 'O';
                    string res = whoWins (b);
                    if (res == "DRAW") canDraw = true;
                    if (res == "FIRST") canWin = true;
                    
                    b[i][j] = '.';
                    if (canWin) break;
                }
            }
        if (canWin) return "FIRST";
        if (canDraw) return "DRAW";
        return "SECOND";
    }
}

int main (int args, char const *argv[]) {
    vector<string> b;
    string input;
    
    for (int i = 0; i < 3; i++) {
        cin >> input;
        input.erase (remove (input.begin (), input.end (), '{'), input.end ());
        input.erase (remove (input.begin (), input.end (), '"'), input.end ());
        input.erase (remove (input.begin (), input.end (), ','), input.end ());
        input.erase (remove (input.begin (), input.end (), '}'), input.end ());
        b.push_back (input);
    }
    
    output.open ("d:/kuliah/PAA/TicSolver_5115100029_511500038/output.txt"); // give full path
    string winner = whoWins (b);
    output << winner << endl << endl;
    while (!step.empty ()) {
        for (int i = 0; i < 3; i++) cout << step.front ()[i] << endl;
        output << endl;
        step.pop ();
    }
}