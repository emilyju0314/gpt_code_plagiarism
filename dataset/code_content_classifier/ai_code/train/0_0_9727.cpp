#include <iostream>
#include <vector>

const int MOD = 998244353;

int n, k;
std::vector<std::vector<int>> adj;
std::vector<std::vector<std::vector<int>>> dp;

void dfs(int u, int parent) {
    dp[u][0][0] = 1;
    dp[u][1][1] = 1;

    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);

        std::vector<std::vector<int>> temp(k + 1, std::vector<int>(2, 0));
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k - i; j++) {
                temp[i + j][0] = (temp[i + j][0] + 1LL * dp[u][i][0] * dp[v][j][0]) % MOD;
                temp[i + j][1] = (temp[i + j][1] + 1LL * dp[u][i][1] * dp[v][j][0] % MOD + 1LL * dp[u][i][1] * dp[v][j][1] % MOD + 1LL * dp[u][i][0] * dp[v][j][1] % MOD) % MOD;
            }
        }
        dp[u] = temp;
    }
}

int main() {
    std::cin >> n >> k;

    adj.resize(n);
    dp.resize(n, std::vector<std::vector<int>>(k + 1, std::vector<int>(2, 0)));

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[0][i][1]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}