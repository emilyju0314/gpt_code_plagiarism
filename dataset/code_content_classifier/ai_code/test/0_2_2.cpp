#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n, m, k;
int arr[MAXN];

ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    if (k == 1) {
        ans = (ll)n * m * (m + 1) / 2;
        ans %= MOD;
    } else {
        vector<ll> cnt(k, 0);
        ll sum = 0;
        cnt[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            sum %= k;
            cnt[sum]++;
        }

        for (int i = 0; i < k; i++) {
            ans += (cnt[i] * (cnt[i] - 1)) / 2;
            ans %= MOD;
        }

        ans *= power(power(n, m), MOD - 2);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}