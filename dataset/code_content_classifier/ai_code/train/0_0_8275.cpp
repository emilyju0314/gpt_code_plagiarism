#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int n, m;
vector<vector<Edge>> adj;
vector<int> costs;
vector<long long> min_cost;
vector<bool> visited;
map<pair<int, int>, int> worker_costs;

void dfs(int node, int prev) {
    for (Edge& edge : adj[node]) {
        if (edge.to != prev) {
            min_cost[edge.to] = min(min_cost[node], (long long)edge.weight);
            dfs(edge.to, node);
        }
    }
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    costs.resize(n + 1);
    min_cost.resize(n + 1, 1e18);
    visited.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, 0});
        adj[b].push_back({a, 0});
    }

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        worker_costs[{u, v}] = c;
    }

    min_cost[1] = 0;
    dfs(1, -1);

    long long total_cost = 0;
    for (auto& worker : worker_costs) {
        int u = worker.first.first;
        int v = worker.first.second;
        int c = worker.second;
        total_cost += min(min_cost[u], min_cost[v]) * c;
    }

    for (int i = 1; i <= n; i++) {
        if (min_cost[i] == 1e18) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total_cost << endl;

    return 0;
}