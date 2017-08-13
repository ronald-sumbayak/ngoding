#include <cstdio>

char board[50][50];
int h, w, max;

bool inBounds (int x, int y) {
    return (x>=0 && x<w) && (y>=0 && y<h);
}

void isArbit (int x, int y) {
    int cell = board[y][x] - '0';
    if (board[y-cell][x] == cell + '0') max = -1;
    if (board[y][x+cell] == cell + '0') max = -1;
    if (board[y+cell][x] == cell + '0') max = -1;
    if (board[y][x-cell] == cell + '0') max = -1;
}

void jump (int x, int y, int step) {
    if (!inBounds (x, y)) return;
    
    int cell = board[y][x];
    if (cell == 'H') return;
    cell -= '0';
    
    isArbit (x, y);
    if (max == -1) return;
    if (step > max) max = step;
    
    jump (x, y-cell, step+1);
    jump (x+cell, y, step+1);
    jump (x, y+cell, step+1);
    jump (x-cell, y, step+1);
}

int main (int args, char const *argv[]) {
    max = 0;
    scanf ("%d %d", &h, &w);
    for (int i = 0; i < h; i++) scanf ("%s", board[i]);
    jump (0, 0, 1);
    printf ("%d\n", max);
}