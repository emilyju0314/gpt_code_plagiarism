#include <iostream>
#include <vector>

const int MOD = 1000000007;

using namespace std;

vector<vector<int>> adj_list;
vector<int> dp1, dp2, sz;
int k, x;

void dfs(int u, int parent) {
    sz[u] = 1;
    dp1[u] = 1;
    dp2[u] = 0;

    for (int v : adj_list[u]) {
        if (v == parent) continue;

        dfs(v, u);
        sz[u] += sz[v];
        
        dp1[u] = (1LL * dp1[u] * dp1[v]) % MOD;

        if (sz[v] == 1) {
            dp2[u] = (dp2[u] + 1) % MOD;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj_list.resize(n + 1);
    dp1.resize(n + 1);
    dp2.resize(n + 1);
    sz.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    cin >> k >> x;

    dfs(1, 0);

    int ans = 0;

    for (int v : adj_list[1]) {
        int cur_dp1 = dp1[1];
        int cur_dp2 = dp2[1];

        cur_dp1 = (1LL * cur_dp1 * dp1[v]) % MOD;

        if (sz[v] == 1) {
            cur_dp2--;
        }

        ans = (ans + cur_dp1) % MOD;
    }

    cout << ans << endl;

    return 0;
}