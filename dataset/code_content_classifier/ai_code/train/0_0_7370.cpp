#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> beauty(n);
    for (int i = 0; i < n; i++) {
        std::cin >> beauty[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long ans = 0;
    std::vector<long long> dp(n, 0);

    std::function<void(int, int)> dfs = [&](int u, int p) {
        dp[u] = beauty[u];
        ans = (ans + dp[u]) % MOD;

        for (int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            long long g = gcd(beauty[u], beauty[v]);
            dp[u] = (dp[u] + dp[v] * g) % MOD;
        }
    };

    dfs(0, -1);

    std::cout << ans << std::endl;

    return 0;
}