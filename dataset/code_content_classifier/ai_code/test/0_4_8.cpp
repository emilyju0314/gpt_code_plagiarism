#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
vector<int> illusion_rate;
vector<int> dp;

void dfs(int u, int parent) {
    dp[u] = abs(illusion_rate[u]);

    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            dp[u] = max(dp[u], dp[u] + dp[v] - abs(illusion_rate[u] - illusion_rate[v]));
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    illusion_rate.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> illusion_rate[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(n);
    dfs(0, -1);

    for (int i = 0; i < q; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        u--;

        if (type == 1) {
            illusion_rate[u] = v;
            dfs(0, -1);
        } else {
            cout << dp[u] << endl;
        }
    }

    return 0;
}