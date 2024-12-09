#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, q;
vector<vector<int>> adj;
vector<pair<int, int>> paths;
unordered_set<int> pathSet;

void addPath(int u, int v) {
    paths.push_back({u, v});
    pathSet.insert(u * n + v);
}

void deletePath(int u, int v) {
    pathSet.erase(u * n + v);
    pathSet.erase(v * n + u);
}

void dfs(int node, int parent, vector<bool>& visited, vector<int>& dist, int d) {
    visited[node] = true;

    if (d >= 0) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, visited, dist, d - 1);
            }
        }
    }

    dist[node] = 0;
    for (int neighbor : adj[node]) {
        if (neighbor != parent && visited[neighbor]) {
            dist[node] = max(dist[node], dist[neighbor] + 1);
        }
    }
}

bool checkIntersection(int d) {
    vector<bool> visited(n, false);
    vector<int> dist(n, 0);

    for (auto path : paths) {
        int u = path.first, v = path.second;
        visited[u] = visited[v] = true;
        dfs(u, v, visited, dist, d);
        dfs(v, u, visited, dist, d);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] && dist[i] < d) {
            return false; // intersection of all d-neighborhoods is not empty
        }
    }

    return true;
}

int main() {
    cin >> n >> q;

    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < q; i++) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            addPath(u, v);
        } else if (queryType == 2) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            deletePath(u, v);
        } else {
            int d;
            cin >> d;
            if (!pathSet.empty() && checkIntersection(d)) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }

    return 0;
}