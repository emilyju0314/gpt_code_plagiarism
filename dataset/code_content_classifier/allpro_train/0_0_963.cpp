#include <iostream>
#include <vector>

using namespace std;
const int MOD = 998244353;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int fact[MAXN], inv[MAXN];

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int powmod(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    inv[MAXN - 1] = powmod(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
}

int nCr(int n, int r) {
    return mul(fact[n], mul(inv[r], inv[n - r]));
}

int dfs(int u, int p) {
    int res = 1;
    for (int v : adj[u]) {
        if (v != p) {
            res = mul(res, dfs(v, u));
        }
    }
    return add(res, 1);
}

int main() {
    precompute_factorials();

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans = mul(ans, i);
    }

    for (int i = 1; i <= n; i++) {
        int children = 0;
        for (int v : adj[i]) {
            children++;
        }
        ans = mul(ans, nCr(n - 1, children));
    }

    cout << ans << endl;

    return 0;
}