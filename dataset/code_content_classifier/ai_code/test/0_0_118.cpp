#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int n;
std::vector<std::vector<int>> adj;
std::vector<std::vector<long long>> dp;

void dfs(int node, int parent) {
    dp[node][0] = dp[node][1] = 1;

    for (int child : adj[node]) {
        if (child == parent) continue;

        dfs(child, node);

        dp[node][0] = (dp[node][0] * (dp[child][0] + dp[child][1])) % MOD;
        dp[node][1] = (dp[node][1] * dp[child][0]) % MOD;
    }
}

int main() {
    std::cin >> n;

    adj.resize(n + 1);
    dp.resize(n + 1, std::vector<long long>(2));

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    std::cout << (dp[1][0] + dp[1][1]) % MOD << std::endl;

    return 0;
}