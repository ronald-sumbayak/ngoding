#include <iostream>
#include <cstdio>
#include <set>
#define fori for (unsigned int i = 0; i < str.length (); i++)
#define forj for (unsigned int j = 0; j < str.length ()-i+1; j++)


#define MOD 1000000007
typedef long long int ll;

ll mod_exp (ll b, ll e, ll m) {
    ll r = 1;
    while (e > 0) {
        if ((e&1) == 1) r = (r*b) % m;
        e >>= 1;
        b = (b*b) % m;
    }
    return r;
}

ll fact_mod (ll n) {
    ll x = 1;
    for (int i = 2; i <= n; i++) x = x * i % MOD;
    return x;
}

int main () {
    std::string str;
    ll k, res, n;
    std::set<std::string> m;
    
    std::cin >> str >> k;
    for (unsigned int i = 0; i < str.length (); i++)
        for (unsigned int j = 0; j < str.length ()-i+1; j++)
            m.insert (str.substr (j, i));
    
    n = m.size ();
    if (k > n) res = 0;
    else {
        ll a, b, invb;
        k = std::min (k, n);
        a = fact_mod (n);
        b = (fact_mod (k) * fact_mod (n-k)) % MOD;
        invb = mod_exp (b, MOD - 2, MOD);
        res = (a * invb) % MOD;
    }
    
    printf ("%lld\n", res);
    return 0;
}