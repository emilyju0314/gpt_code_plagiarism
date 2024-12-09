#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Edge {
    int u, v;
};

vector<int> adj[901];
vector<bool> visited;
set<Edge> existingEdges;

void dfs(int u, int v, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == v) {
        for (int i = 0; i < path.size() - 1; i++) {
            existingEdges.insert({path[i], path[i+1]});
        }
    } else {
        for (int child : adj[u]) {
            if (!visited[child]) {
                dfs(child, v, path);
            }
        }
    }

    visited[u] = false;
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<Edge> addedEdges;
    bool reformNeeded = false;

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (existingEdges.find({u, v}) == existingEdges.end()) {
                reformNeeded = true;

                vector<int> path;
                dfs(u, v, path);
            }
        }
    }

    if (!reformNeeded) {
        cout << "0" << endl;
    } else {
        cout << addedEdges.size() << endl;
        for (Edge e : addedEdges) {
            cout << e.u << " " << e.v << endl;
        }
    }

    return 0;
}