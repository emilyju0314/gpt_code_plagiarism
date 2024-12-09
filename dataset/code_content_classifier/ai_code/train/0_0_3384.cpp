#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj_list;
vector<bool> visited;
vector<pair<int, int>> result;

void dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj_list[u]) {
        if (v != parent && !visited[v]) {
            result.push_back(make_pair(u, v));
            dfs(v, u);
        }
    }
}

int main() {
    cin >> n >> m;

    adj_list.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    dfs(1, -1);

    cout << result.size() << endl;
    for (auto edge : result) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}