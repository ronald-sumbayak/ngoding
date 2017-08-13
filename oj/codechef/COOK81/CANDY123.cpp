#include <cstdio>

int main (int argc, char **argv) {
    int tc, a, b;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &a, &b);
        
        int turn=0, c=1;
        while (a >= 0 && b >= 0) {
            if (turn) b -= c;
            else a -= c;
            c++;
            turn = !turn;
        }
        
        if (a >= 0) printf ("Limak\n");
        else printf ("Bob\n");
    }
    
    return 0;
}