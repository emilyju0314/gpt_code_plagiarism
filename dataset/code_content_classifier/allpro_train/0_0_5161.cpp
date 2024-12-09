#include <iostream>
#include <vector>

using namespace std;

bool isBipartite(int n, const vector<vector<int>>& adjList) {
    vector<int> color(n, -1);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            color[i] = 0;
            visited[i] = true;

            vector<int> q;
            q.push_back(i);

            while (!q.empty()) {
                int u = q.back();
                q.pop_back();

                for (int v : adjList[u]) {
                    if (!visited[v]) {
                        color[v] = 1 - color[u];
                        visited[v] = true;
                        q.push_back(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // 0-based indexing

        if (find(adjList[x].begin(), adjList[x].end(), y) == adjList[x].end()) {
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        } else {
            adjList[x].erase(find(adjList[x].begin(), adjList[x].end(), y));
            adjList[y].erase(find(adjList[y].begin(), adjList[y].end(), x));
        }

        if (isBipartite(n, adjList)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}