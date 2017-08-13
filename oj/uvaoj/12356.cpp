#include <cstdio>

int main (int argc, char **argv) {
    int s, b, l, r;
    
    while (scanf ("%d %d", &s, &b)) {
        if (!s && !b) break;
        int left[s+1], right[s+1];
        
        for (int i = 1; i <= s; i++) {
            left[i] = i-1;
            right[i] = i+1;
        }
        
        for (int i = 0; i < b; i++) {
            scanf ("%d %d", &l, &r);
            
            left[right[r]] = left[l];
            if (left[l] == 0) printf ("* ");
            else printf ("%d ", left[l]);
    
    
            right[left[l]] = right[r];
            if (right[r] == s+1) printf ("*\n");
            else printf ("%d\n", right[r]);
        }
        
        printf ("-\n");
    }
    
    return 0;
}