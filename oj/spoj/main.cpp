#include <cstdio>
#include <map>
#include <vector>

int main () {
    int n;
    scanf ("%d", &n);
    if (n < 1) return 0;
    std::map<long long, long long> toffees;
    std::vector<long long> unique;
    
    for (int i = 1; i <= n; i++) {
        long long input;
        scanf ("%lld", &input);
        if (toffees[input]++ == 0) unique.push_back (input);
    }
    
    n = unique.size ();
    for (int i = 0; i < n; i++) printf ("%lld ", unique[i]);
    printf ("\n");
    for (int i = n-1; i >= 0; i--) printf ("%lld ", unique[i]);
    printf ("\n");
    return 0;
}