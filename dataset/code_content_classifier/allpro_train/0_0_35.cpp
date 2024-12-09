#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1e9 + 7;

std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<long long> depth, dp1, dp2;

void dfs(int v, int p) {
    for (auto edge : adj[v]) {
        int u = edge.first, w = edge.second;
        if (u != p) {
            depth[u] = depth[v] + w;
            dfs(u, v);
            dp1[v] += dp1[u];
            dp2[v] += (dp2[u] + w * dp1[u] % MOD) % MOD;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    adj.resize(n);
    depth.resize(n);
    dp1.resize(n);
    dp2.resize(n);

    for (int i = 1; i < n; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    dfs(0, -1);

    int q;
    std::cin >> q;

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;

        long long ans = 0;
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }

        long long p1 = dp1[u], p2 = dp2[u];
        for (int i = 31; i >= 0; i--) {
            if (depth[u] - depth[v] >= (1 << i)) {
                ans = (ans + (p2 - ((p1 * dp1[v]) % MOD) + MOD) % MOD) % MOD;
                p1 = (p1 - dp1[v] + MOD) % MOD;
                p2 = (p2 - (dp2[v] + dp1[v] * depth[v]) + MOD) % MOD;
                u = v;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}