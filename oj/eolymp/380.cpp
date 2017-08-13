#include <cstdio>
#include <cstdlib>

void getBoardInput (char***, int);
void fillBoard (int, int, char, char);
int walkEntrance (int, int, int);
int walkBoard (int, int, int);
int checkSurround (int x, int y, int);
bool checkHorizontal (int, int x);
bool checkVertical (int, int x);
int max (int, int, int, int);
bool isChar (int, int, char);
bool isInRange (int) ;

int maxRooks = 0;
int boardSize;
char **board;

int main () {
    scanf ("%d", &boardSize);
    getBoardInput (&board, boardSize);
    
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++)
        {
            if (isChar (x, y, '.')) {
                fillBoard (x, y, '.', '-');
                walkEntrance (x, y, maxRooks);
            }
        }
    }

    printf ("%d\n", maxRooks);
    return 0;
}

void fillBoard (int x, int y, char from, char to) {
    board[y][x] = to;

    if (isChar (x, y-1, from)) fillBoard (x, y-1, from, to);
    if (isChar (x, y+1, from)) fillBoard (x, y+1, from, to);
    if (isChar (x-1, y, from)) fillBoard (x-1, y, from, to);
    if (isChar (x+1, y, from)) fillBoard (x+1, y, from, to);
}

bool isChar (int x, int y, char symbol) {
    if (isInRange (x) && isInRange (y)) {
        return board[y][x] == symbol;
    }
    else {
        return false;
    }
}

bool isInRange (int i) {
    return i >= 0 && i < boardSize;
}

void getBoardInput (char ***board, int boardSize) {
    *board = (char **) malloc (boardSize * sizeof (char*));

    for (int x = 0; x < boardSize; x++) {
        (*board)[x] = (char *) malloc (boardSize * sizeof (char));
        scanf ("%s", (*board)[x]);
    }
}

int walkEntrance (int x, int y, int rooks) {
    for (int j = 0; j < boardSize; j++) {
        for (int i = 0; i < boardSize; i++)
        {
            if (isChar (i, j, '-')) {
                rooks = walkBoard (i, j, rooks);
                fillBoard (x, y, '*', '-');
                board[y][x] = '+';
            }
        }
    }

    return maxRooks;
}

int walkBoard (int x, int y, int rooks) {
    if (checkHorizontal (x, y) && checkVertical (x, y)) {
        rooks++;
        board[y][x] = 'O';
    }
    else {
        board[y][x] = ',';
    }

    if (rooks > maxRooks) {
        maxRooks = rooks;
    }

    rooks = checkSurround (x, y, rooks);

    board[y][x] = '*';
    return rooks;
}

int checkSurround (int x, int y, int rooks) {
    int u, d, r, l;
    u = d = r = l = 0;

    if (isChar (x, y-1, '-') || isChar (x, y-1, '+')) u = walkBoard (x, y-1, rooks);
    if (isChar (x, y+1, '-') || isChar (x, y+1, '+')) d = walkBoard (x, y+1, rooks);
    if (isChar (x-1, y, '-') || isChar (x-1, y, '+')) l = walkBoard (x-1, y, rooks);
    if (isChar (x+1, y, '-') || isChar (x+1, y, '+')) r = walkBoard (x+1, y, rooks);

    return max (u, d, r, l);
}

int max (int up, int down, int right, int left) {
    int max = up;

    if (down > max) max = down;
    if (right > max) max = right;
    if (left > max) max = left;
    return max;
}

bool checkHorizontal (int x, int y) {
    for (int i = x+1; i < boardSize; i++) {
        switch (board[y][i]) {
            case 'O': return false;
            case 'X': break;
            default: continue;
        }
        break;
    }

    for (int i = x-1; i >= 0; i--) {
        switch (board[y][i]) {
            case 'O': return false;
            case 'X': break;
            default: continue;
        }
        break;
    }
    return true;
}

bool checkVertical (int x, int y) {
    for (int i = y+1; i < boardSize; i++) {
        switch (board[i][x]) {
            case 'O': return false;
            case 'X': break;
            default: continue;
        }
        break;
    }

    for (int i = y-1; i >= 0; i--) {
        switch (board[i][x]) {
            case 'O': return false;
            case 'X': break;
            default: continue;
        }
        break;
    }
    return true;
}