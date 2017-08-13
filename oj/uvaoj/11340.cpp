#include <cstdio>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

int main (int argc, char **argv) {
    int n, k, m, price;
    char c, article[10001];
    cin >> n;
    
    while (n--) {
        std::map<char, int> table;
        cin >> k;
        
        for (int i = 0; i < k; i++) {
            cin >> c >> price;
            table.insert (std::make_pair (c, price));
        }
        
        cin >> m;
        getchar ();
        price = 0;
        
        for (int i = 0; i < m; i++) {
            gets (article);
            for (int j = 0; j < strlen (article); j++) price += table[article[j]];
        }
    
        printf ("%.2lf$\n", price/100.0);
    }
    
    return 0;
}