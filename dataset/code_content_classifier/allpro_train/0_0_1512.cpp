#include <iostream>
#include <vector>

const int MOD = 1000000007;

std::vector<std::vector<int>> adj;
std::vector<int> subtreeSize;
std::vector<int> values;

void update(int v, int x, int k, int level) {
    values[v] = (values[v] + x - 1LL * level * k % MOD + MOD) % MOD;
    for (int u : adj[v]) {
        update(u, x, k, level + 1);
    }
}

int query(int v) {
    return values[v];
}

int main() {
    int n;
    std::cin >> n;

    adj.resize(n + 1);
    subtreeSize.resize(n + 1, 0);
    values.resize(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        int p;
        std::cin >> p;
        adj[p].push_back(i);
    }

    int q;
    std::cin >> q;

    while (q--) {
        int type;
        std::cin >> type;

        if (type == 1) {
            int v, x, k;
            std::cin >> v >> x >> k;
            update(v, x, k, 0);
        } else {
            int v;
            std::cin >> v;
            std::cout << query(v) << std::endl;
        }
    }

    return 0;
}