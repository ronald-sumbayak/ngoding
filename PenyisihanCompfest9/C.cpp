#include <cstdio>
#include <queue>

int input () {
    int numb;
    scanf ("%d", &numb);
    return numb;
}

int main (int argc, char **argv) {
    int tc, m, n;
    scanf ("%d", &tc);
    
    while (tc--) {
        scanf ("%d %d", &m, &n);
        std::queue<int> chanek, dzul;
        
        for (int i = 0; i < n; i++)
            chanek.push (input ());
    
        for (int i = 0; i < n; i++)
            dzul.push (input ());
        
        int c=0, d=m/2, rotation=0;
        
        while (n--) {
            int to_c = 
        }
    }
}