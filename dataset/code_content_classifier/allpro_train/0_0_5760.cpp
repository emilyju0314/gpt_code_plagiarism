#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> neighbors;
vector<bool> visited;
vector<int> count;

void dfs(int v) {
    count[v]++;
    if (count[v] < 1000) {
        for (int u : neighbors[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
    }
    visited[v] = true;
}

void TOF() {
    for (auto& entry : neighbors) {
        sort(entry.second.begin(), entry.second.end());
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    neighbors.resize(n + 1);
    visited.resize(n + 1, false);
    count.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
    }

    TOF();

    int min_dfs_calls = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            min_dfs_calls++;
        }
    }

    cout << min_dfs_calls * 1000 + 2 << endl;

    return 0;
}