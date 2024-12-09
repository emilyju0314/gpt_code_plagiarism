#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll MOD = 1e9 + 7;

ll factorial(ll n, ll m = 2) {
    // calculate n!
    m = max(2LL, m);
    ll rtn = 1;
    for (ll i = m; i <= n; i++) {
        rtn = (rtn * i) % MOD;
    }
    return rtn;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main() {
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    ll ans = 0;
    ll factor = factorial(n - 1);
    ll running = factor;
    for (int i = 0; i < n - 1; i++) {
        ll d = x[i + 1] - x[i];
        ans += (running % MOD) * (d % MOD);
        ans %= MOD;
        running += (factor * modinv(i + 2, MOD)) % MOD;
    }
    cout << ans << endl;
}