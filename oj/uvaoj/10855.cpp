#include <cstdio>
bool contains (int, int, int);
void rotate (int);
int match (int, int);

char s1[500][500], s2[500][500];
int main (int argc, char **argv) {
    int N, n;
    
    while (scanf ("%d %d", &N, &n)) {
        if (!N && !n) break;
        for (int i = 0; i < N; i++) scanf ("%s", s1[i]);
        for (int i = 0; i < n; i++) scanf ("%s", s2[i]);
        
        for (int i = 0; i < 4; i++) {
            if (i) printf (" ");
            printf ("%d", match (N, n));
            rotate (n);
        }
        
        printf ("\n");
    }
    
    return 0;
}

int match (int N, int n) {
    int occurence = 0;
    for (int j = 0; j <= N-n; j++) {
        for (int k = 0; k <= N-n; k++) {
            if (contains (n, j, k)) {
                occurence++;
            }
        }
    }
    return occurence;
}

bool contains (int n, int y, int x) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (s1[y + i][x + j] != s2[i][j]) return false;
        }
    
    return true;
}

void rotate (int n) {
    char temp[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = s2[n-j-1][i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s2[i][j] = temp[i][j];
        }
    }
}