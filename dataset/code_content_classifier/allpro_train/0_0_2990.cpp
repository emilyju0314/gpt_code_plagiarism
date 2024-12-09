#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;

    vector<int> fact(n * m + 1);
    fact[0] = 1;
    for (int i = 1; i <= n * m; i++) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }

    vector<int> inv_fact(n * m + 1);
    inv_fact[n * m] = pow(fact[n * m], MOD - 2);
    for (int i = n * m - 1; i >= 0; i--) {
        inv_fact[i] = (1LL * inv_fact[i + 1] * (i + 1)) % MOD;
    }

    auto C = [&](int n, int k) {
        if (k < 0 || k > n) return 0;
        return (1LL * fact[n] * inv_fact[k] % MOD * inv_fact[n-k] % MOD);
    };

    int p = (1LL * a * pow(b, MOD - 2)) % MOD;
    int q = pow((1 + p) % MOD, n) * 1LL * pow((1 + p) % MOD, m) % MOD;
    int r = pow(q, k) % MOD;

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int cur = (1LL * C(n, i) * C(m, j) % MOD) * pow(q, n * m - i * j) % MOD;
            if ((n - i) % 2) cur = MOD - cur;
            if ((n - i) % 2) cur = MOD - cur;
            ans = (ans + 1LL * cur * pow(r, MOD - 2)) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}