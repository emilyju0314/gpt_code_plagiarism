#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int target, unordered_set<int>& path) {
    if (curr == target) {
        return true;
    }

    visited[curr] = true;
    path.insert(curr);

    for (int next : graph[curr]) {
        if (!visited[next] && dfs(graph, visited, next, target, path)) {
            return true;
        }
    }

    path.erase(curr);
    return false;
}

bool canReverseSnake(vector<vector<int>>& graph, int head, int tail) {
    int n = graph.size();
    vector<bool> visited(n, false);
    unordered_set<int> headPath, tailPath;

    dfs(graph, visited, head, tail, headPath);
    cout << endl;
    dfs(graph, visited, tail, head, tailPath);

    for (int vertex : headPath) {
        if (tailPath.count(vertex) > 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<vector<int>> graph(n+1);
        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (canReverseSnake(graph, a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}