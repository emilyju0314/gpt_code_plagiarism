#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 100005;

int n, m, q;
int e[MAX_N];
int ans[MAX_N];

int inv[MAX_N];
int fact[MAX_N];
int inv_fact[MAX_N];

int binpow(int a, int b) {
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

void precompute() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (1LL * fact[i-1] * i) % MOD;
        inv[i] = binpow(i, MOD - 2);
        inv_fact[i] = (1LL * inv_fact[i-1] * inv[i]) % MOD;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    int res = (1LL * fact[n] * inv_fact[r]) % MOD;
    res = (1LL * res * inv_fact[n-r]) % MOD;
    return res;
}

int main() {
    precompute();

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int cnt = nCr(r - l + (k * m), r - l);

        ans[q] = (1LL * cnt * inv[nCr(n + (k * m), n)]) % MOD;
    }

    for (int i = q - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }

    return 0;
}