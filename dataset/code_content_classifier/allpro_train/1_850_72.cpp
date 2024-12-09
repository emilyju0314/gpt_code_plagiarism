#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define all(c) (c).begin(), (c).end()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

ll inv[N], fact[N], ifact[N], pot[N];

ll comb(int m, int n) {
    if (n < 0 || n > m) return 0;
    return fact[m] * ifact[n] % MOD * ifact[m-n] % MOD;
}

void add(int &a, ll b) {
    a += b%MOD;
    if (a >= MOD) a-= MOD;
    if (a < 0) a += MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    inv[1] = 1; forsn(n,2,N) inv[n] = (MOD - MOD/n) * inv[MOD%n] % MOD;
    fact[0] = 1; forsn(n,1,N) fact[n] = n * fact[n-1] % MOD;
    ifact[0] = 1; forsn(n,1,N) ifact[n] = inv[n] * ifact[n-1] % MOD;
    pot[0] = 1; forsn(n,1,N) pot[n] = pot[n-1]*3 % MOD;

    int a,b,c; cin >> a >> b >> c;


    ll res = 0;
    int l = 0, r = b; ll inter = 1;
    for (int yz = 0; yz <= b+c; yz++) {
        while (l < yz-c) {
            inter -= comb(yz,l++);
            if (inter < 0) inter += MOD;
        }

        res += inter * comb(a-1+yz,a-1) % MOD * pot[b+c-yz] % MOD;

        inter = 2*inter - comb(yz,r) + comb(yz,l-1);
        inter %= MOD; if (inter < 0) inter += MOD;
    }
    res %= MOD;
    cout << res << endl;
    return 0;
}
