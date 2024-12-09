#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> outDegree;
set<vector<int>> validTuples;

void dfs(int u, int start, int prevWeight, int steps) {
    if (visited[u]) {
        if (u == start && steps == k) {
            validTuples.insert(outDegree);
        }
        return;
    }

    visited[u] = true;
    outDegree[steps] = prevWeight;
    for (auto edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        dfs(v, start, weight, steps + 1);
    }
    visited[u] = false;
}

int main() {
    cin >> n >> m >> k;
    
    adj.resize(n + 1);
    visited.resize(n + 1, false);
    outDegree.resize(k);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for (int u = 1; u <= n; ++u) {
        dfs(u, u, -1, 0);
    }

    cout << validTuples.size() << endl;

    return 0;
}