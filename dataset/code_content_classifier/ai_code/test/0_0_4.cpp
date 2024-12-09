#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<pair<int, int>>> adj;
vector<long long> a;
int k;
long long ans = 0;

pair<int, int> dfs(int u, int par) {
    long long sum = 0;
    pair<int, int> res = {0, 0};

    for (auto [v, t] : adj[u]) {
        if (v != par) {
            auto [subsize, subres] = dfs(v, u);
            res.first += subsize;
            res.second += subres;

            sum += a[v - 1];
            sum += subsize * a[v - 1];
        }
    }

    if (k == 0) {
        ans = (ans + sum) % MOD;
    } else {
        res.first++;
        res.second += sum;

        if (res.first <= k) {
            ans = (ans + sum) % MOD;
        } else {
            ans = (ans + (res.second - sum) * (k + 1)) % MOD;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}