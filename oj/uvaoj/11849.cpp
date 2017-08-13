#include <cstdio>
#include <set>
long long getNumb ();

int main (int argc, char const *argv[]) {
    int n, m, both;
    std::set<long long> cds;
    
    while (scanf ("%d %d", &n, &m)) {
        both = 0;
        if (!n && !m) break;
        while (n--) cds.insert (getNumb ());
        while (m--) if (!cds.insert (getNumb ()).second) both++;
        printf ("%d\n", both);
        cds.clear ();
    }
    return 0;
}

long long getNumb () {
    long long n;
    scanf ("%lld", &n);
    return n;
}