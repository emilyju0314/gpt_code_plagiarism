#include <iostream>
#include <vector>

using namespace std;

int minEdgesToAdd(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adjList(n + 1);
    vector<int> depth(n + 1, 0);

    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    function<void(int, int, int)> dfs = [&](int node, int parent, int level) {
        depth[node] = level;
        for (int neighbor : adjList[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, level + 1);
            }
        }
    };

    dfs(1, -1, 0);

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (depth[i] <= 2) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int result = minEdgesToAdd(n, edges);
    cout << result << endl;

    return 0;
}