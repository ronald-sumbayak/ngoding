#include <cstdio>
#include <vector>
#include <bitset>
#include <cstdlib>

int main (int argc, char **argv) {
    unsigned int n;
    int input, prev;
    
    while (scanf ("%d", &n) != EOF) {
        std::vector<int> numbs;
        bool state[n-1]={};
        scanf ("%d", &prev);
        
        for (int i = 1; i < n; i++) {
            scanf ("%d", &input);
            state[std::abs (input-prev) - 1] = true;
            prev = input;
        }
        
        int i = 0;
        while (state[0] && (i < n-1)) state[0] &= state[i++];
        if (state[0]) printf ("Jolly\n");
        else printf ("Not jolly\n");
    }
    
    return 0;
}