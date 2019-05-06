#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;


ll mulmod (ll a, ll b, ll c) {
    ll R = 0;
    for(;b;b>>=1){
        if(b & 1) R = (R + a) % c;
        a = (a + a) % c;
    }
    return R;
}

ll expmod (ll b, ll e, ll m) {
    if(!e) return 1;

    ll q = expmod(b, e / 2, m);
    q = mulmod(q, q, m);
    return e % 2 ? mulmod(b, q, m) : q;
}


bool es_primo_prob (ll n, int a) {
    if (n == a) return true;
    ll s = 0, d = n - 1;
    while (d % 2 == 0) s++, d /= 2;
    ll x = expmod(a, d, n);
    if ((x == 1) || (x + 1 == n)) return true;
    for(int i=0;i<s-1;i++) {
        x = mulmod(x, x, n);
        if (x == 1) return false;
        if (x + 1 == n) return true;
    }
    return false;
}

ll rho(ll n) {
    if( (n & 1) == 0 ) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n + 1;
    while( d == 1 ) {
        x = (mulmod( x, x, n ) + c) % n;
        y = (mulmod( y, y, n ) + c) % n;
        y = (mulmod( y, y, n ) + c) % n;

        if( x - y >= 0 ) d = __gcd( x - y, n );
        else d = __gcd( y - x, n );
    }

    return d == n ? rho(n) : d;
}
bool rabin (ll n) {
    if (n == 1) return false;
    const int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for(int j=0;j<9;j++)
    if (!es_primo_prob(n, ar[j]))
        return false;

    return true;
}

vector<ll> prim;
void factRho (ll n) {
    if (n == 1) return;
    if (rabin(n)) {
        prim.push_back(n);
        return;
    }
    ll factor = rho(n);
    factRho(factor);
    factRho(n / factor);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, x, caso = 1;
    cin >> t;
    while(t--) {
        cin >> x;
        prim.clear();
        factRho(x);
        sort(prim.begin(), prim.end());
        int i = 0;
        while(i < prim.size() && prim[i] == 2) i++;
        ll exp = 0;
        ll ant = -1;
        ll R = 1;
        for(;i<prim.size();i++){
            if(i + 1 < prim.size() && prim[i] == prim[i + 1]) exp++;
            else{
                exp+=2;
                R*= exp;
                exp = 0;
            }
        }
        cout << "Case " << caso++ << ": " << R - 1 << "\n";
    }
    return 0;
}
