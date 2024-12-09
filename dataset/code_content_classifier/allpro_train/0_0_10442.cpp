#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int n, k;
vector<vector<int>> adj_list;
vector<vector<int>> dp;
vector<vector<int>> dp2;

void dfs(int v, int parent) {
    dp[v][0] = 1;
    dp2[v][0] = 1;
    for (int u : adj_list[v]) {
        if (u == parent) continue;
        dfs(u, v);
        vector<int> new_dp(k + 2, 0);
        vector<int> new_dp2(k + 2, 0);
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (i + j + 1 <= k + 1) {
                    new_dp[max(i, j + 1)] = (new_dp[max(i, j + 1)] + 1LL * dp[v][i] * dp[u][j] % MOD) % MOD;
                    new_dp2[max(i, j + 1)] = (new_dp2[max(i, j + 1)] + 1LL * dp2[v][i] * dp[u][j] % MOD) % MOD;
                }
            }
        }
        dp[v] = new_dp;
        dp2[v] = new_dp2;
    }
}

int main() {
    cin >> n >> k;

    adj_list.resize(n + 1);
    dp.resize(n + 1, vector<int>(k + 2, 0));
    dp2.resize(n + 1, vector<int>(k + 2, 0));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 0);

    int total_ways = 0;
    for (int i = 0; i <= k; i++) {
        total_ways = (total_ways + dp2[1][i]) % MOD;
    }

    cout << total_ways << endl;

    return 0;
}