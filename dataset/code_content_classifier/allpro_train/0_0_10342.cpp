#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int n, m;
    vector<vector<int>> adj;
    vector<int> deg;
    vector<int> dp, dp2;

    Graph(int n, int m) : n(n), m(m), adj(n + 1), deg(n + 1), dp(n + 1), dp2(n + 1) {}

    void addEdge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    void dfs(int v, int p) {
        dp[v] = 1;

        for (int u : adj[v]) {
            if (u == p) continue;
            dfs(u, v);

            if (deg[u] == 1) {
                dp[v] += dp[u];
            } else {
                dp2[v] = max(dp2[v], dp[u]);
            }
        }

        sort(adj[v].begin(), adj[v].end(), [&](int u, int w) {
            return dp[u] - (deg[u] != 1) < dp[w] - (deg[w] != 1); 
        });

        for (int u : adj[v]) {
            if (deg[u] != 1) {
                dp2[v] = max(dp2[v], dp[v] + dp2[u]);
                dp[v] = max(dp[v], dp[v] + dp[u]);
            }
        }
    }

    void countToys() {
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                dfs(i, 0);
                cout << dp[i] << " ";
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n, m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    g.countToys();

    return 0;
}