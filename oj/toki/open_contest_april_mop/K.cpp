#include <cstdio>

int main () {
    int k, k2;
    scanf ("%d", &k);
    
    while (k--) {
        scanf ("%d", &k2);
        if (k2 <= 4) printf ("Kuku\n");
        else if (k2 <= 8) printf ("Kaki\n");
        else if (k2 <= 14) printf ("Kakak\n");
        else if (k2 <= 17) printf ("Kakek\n");
        else if (k2 <= 21) printf ("Kakekku\n");
        else if (k2 <= 23) printf ("Kok\n");
        else printf ("Kaku\n");
    }
}