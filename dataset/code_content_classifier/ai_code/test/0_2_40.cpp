#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> path;

void dfs(int node, int dest) {
    visited[node] = 1;
    path.push_back(node);

    if (node == dest) {
        // Increment edge weights along the path by 1
        for (int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i + 1];
            // Increment edge weight
            // Note: You need to have edge weight stored in the graph structure
            // graph[u][v]++;
            // graph[v][u]++;
        }
        path.pop_back();
        return;
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, dest);
        }
    }

    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int q;
    cin >> q;

    cout << "YES" << endl;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        path.clear();
        dfs(a, b);

        // Output the chosen path for query i
        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}