#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }

    vector<vector<int>> idealPaths(n + 1, vector<int>(n + 1, INF));
    for (int s = 1; s <= n; s++) {
        vector<int> dist(n + 1, INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adjList[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (int t = 1; t <= n; t++) {
            idealPaths[s][t] = dist[t];
        }
    }

    for (int i = 0; i < q; i++) {
        int sj, tj, kj;
        cin >> sj >> tj >> kj;

        if (idealPaths[sj][tj] == INF || idealPaths[sj][tj] < kj) {
            cout << -1 << endl;
        } else {
            int city = sj;
            int remaining = kj;
            while (remaining > 1) {
                for (int nextCity : adjList[city]) {
                    if (idealPaths[nextCity][tj] == idealPaths[city][tj] - 1) {
                        city = nextCity;
                        break;
                    }
                }
                remaining--;
            }
            cout << city << endl;
        }
    }

    return 0;
}