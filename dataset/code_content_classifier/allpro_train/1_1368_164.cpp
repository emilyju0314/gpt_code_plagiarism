#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> f(N + 1, 1);
    rep(i, N) {
        f[i + 1] = (f[i] * (i + 1)) % MOD;
    }
    ll ans = mod_pow(3, N, MOD);
    for (int i = N / 2 + 1; i <= N; i++) {
        ll x = f[N] * mod_pow(f[i], MOD - 2, MOD);
        x %= MOD;
        x *= mod_pow(f[N - i], MOD - 2, MOD);
        x %= MOD;
        x *= mod_pow(2, N - i, MOD) * 2;
        x %= MOD;
        ans += MOD - x;
        ans %= MOD;
    }
    cout << ans << endl;
}