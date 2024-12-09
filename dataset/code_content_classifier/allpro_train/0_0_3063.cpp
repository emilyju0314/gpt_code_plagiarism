#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int color[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(color, color+n+1, 0);
    fill(dist, dist+n+1, -1);

    color[1] = 1;
    bfs(1);

    for (int i = 0; i < m; i++) {
        int type, node;
        cin >> type >> node;

        if (type == 1) {
            color[node] = 1;
        } else {
            int min_dist = INT_MAX;
            for (int j = 1; j <= n; j++) {
                if (color[j] == 1) {
                    min_dist = min(min_dist, dist[node]);
                }
            }
            cout << min_dist << endl;
        }
    }

    return 0;
}