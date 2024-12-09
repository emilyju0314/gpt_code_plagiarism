#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> colors;
int k;

pair<int, int> dfs(int node, int parent) {
    int red_nodes = colors[node] == 1;
    int blue_nodes = colors[node] == 2;

    for (int child : adj[node]) {
        if (child != parent) {
            auto p = dfs(child, node);
            red_nodes += p.first;
            blue_nodes += p.second;
        }
    }

    int suboptimal_red = min(red_nodes, k);

    return {suboptimal_red, min(red_nodes - suboptimal_red, blue_nodes)};
}

int main() {
    int n;
    cin >> n >> k;

    adj.resize(n + 1);
    colors.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> colors[i];
    }

    auto result = dfs(1, 0);

    int white_nodes = n - result.first - result.second;
    int score = white_nodes * (result.first - result.second);

    cout << score << endl;

    return 0;
}