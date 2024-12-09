#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

ll ceiling(ll a, ll b) {
    return (a - 1 + b) / b;
}

int main() {
    int k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];

    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;
        ll last = x, eq = 0;
        rep(i, k) {
            ll num = ceiling(n - 1 - i, k);
            last += (d[i] % m) * num;
            if (d[i] % m == 0) eq += num;
        }
        ll ans = (n - 1) - (last / m - x / m) - eq;
        cout << ans << endl;
    }
}