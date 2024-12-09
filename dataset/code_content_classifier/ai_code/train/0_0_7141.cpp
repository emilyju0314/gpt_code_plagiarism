#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> path;
int n, m;

bool dfs(int v, int start, int finish) {
    if (v == finish) return true;
    if (visited[v]) return false;

    visited[v] = true;
    path.push_back(v);

    for (int u : adj[v]) {
        if (u != start && u != finish) {
            if (dfs(u, start, finish)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

int main() {
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if ((int)adj[i].size() == 2) {
            int start = adj[i][0];
            int finish = adj[i][1];

            path.clear();
            if (dfs(start, i, finish)) {
                cout << "YES" << endl;
                cout << path.size() + 1 << " " << start << " ";
                for (int p : path) {
                    cout << p << " ";
                }
                cout << finish << endl;

                path.clear();
                if (dfs(start, i, finish)) {
                    cout << path.size() + 1 << " " << start << " ";
                    for (int p : path) {
                        cout << p << " ";
                    }
                    cout << finish << endl;

                    path.clear();
                    if (dfs(start, i, finish)) {
                        cout << path.size() + 1 << " " << start << " ";
                        for (int p : path) {
                            cout << p << " ";
                        }
                        cout << finish << endl;

                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}