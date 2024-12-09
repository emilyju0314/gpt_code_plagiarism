#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> color;
vector<bool> visited;

void dfs(int u, int c) {
    visited[u] = true;
    color[u] = c;

    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, (c + 1) % color.size());
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);
    color.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int maxColors = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 1);
            maxColors = max(maxColors, *max_element(color.begin(), color.end()));
        }
    }

    cout << maxColors << endl;

    return 0;
}