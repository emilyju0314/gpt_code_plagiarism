#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 10005;

int n, k;
vector<int> adj[MAXN];
int dist[MAXN][MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start][start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[start][v] == -1) {
                dist[start][v] = dist[start][u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        fill(dist[i], dist[i] + n + 1, -1);
        bfs(i);
    }

    vector<pair<int, int>> shortcuts;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int max_dist = 0;
            for (int l = 1; l <= n; l++) {
                max_dist = max(max_dist, min(dist[i][l], dist[j][l]));
            }

            if (max_dist <= k) {
                cnt++;
                shortcuts.push_back({i, j});
            }
        }
    }

    cout << cnt << endl;
    for (pair<int, int> shortcut : shortcuts) {
        cout << shortcut.first << " " << shortcut.second << endl;
    }

    return 0;
}