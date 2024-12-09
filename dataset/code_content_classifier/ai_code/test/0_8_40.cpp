#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adjList;
vector<int> parent;
vector<bool> visited;
vector<unordered_set<int>> queries;

void dfs(int node, int dest, unordered_set<int>& path) {
    visited[node] = true;
    path.insert(node);

    if (node == dest) {
        queries.push_back(path);
        return;
    }

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            dfs(neighbor, dest, path);
            path.erase(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1);
    parent.resize(n + 1);
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        queries.clear();
        parent.assign(n + 1, -1);
        unordered_set<int> path;

        dfs(a, b, path);

        bool oddWeight = false;
        for (const auto& path : queries) {
            for (int j = 1; j < n; j++) {
                if (path.count(j) && path.count(parent[j])) {
                    oddWeight = true;
                    break;
                }
            }
        }

        if (oddWeight) {
            cout << "NO" << endl;
            cout << 2 << endl;
        } else {
            cout << "YES" << endl;
            for (const auto& path : queries) {
                cout << path.size() << endl;
                for (int node : path) {
                    cout << node << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}