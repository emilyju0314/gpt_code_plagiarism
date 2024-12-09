#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 3005;
const int INF = 1e9;

vector<int> adj[MAXN];
int dist[MAXN];
bool forbidden[MAXN][MAXN][MAXN];

void bfs(int n) {
    fill(dist, dist + n + 1, INF);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1 && !forbidden[u][v][0]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden[a][b][c] = true;
        forbidden[a][c][b] = true;
        forbidden[b][a][c] = true;
        forbidden[b][c][a] = true;
        forbidden[c][a][b] = true;
        forbidden[c][b][a] = true;
    }

    bfs(n);

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
        vector<int> path;
        path.push_back(n);

        while (dist[path.back()] > 0) {
            int u = path.back();
            for (int v : adj[u]) {
                if (dist[v] == dist[u] - 1) {
                    path.push_back(v);
                    break;
                }
            }
        }

        reverse(path.begin(), path.end());

        for (int city : path) {
            cout << city << " ";
        }
        cout << endl;
    }

    return 0;
}