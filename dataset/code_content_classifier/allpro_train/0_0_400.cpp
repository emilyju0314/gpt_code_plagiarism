#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    vector<int> indegree(n + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;
        indegree[x]++;
        indegree[y]++;
        edges.push_back({x, y});
    }

    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] > 2) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO" << endl;
    } else {
        vector<pair<int, int>> additional_edges;

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (adj[i][j] == 0 && indegree[i] < 2 && indegree[j] < 2) {
                    additional_edges.push_back({i, j});
                    indegree[i]++;
                    indegree[j]++;
                }
            }
        }

        cout << "YES" << endl;
        cout << additional_edges.size() << endl;
        for (auto edge : additional_edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}