#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 3e5 + 5;
vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    parent[start] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int q;
    cin >> q;

    cout << "YES" << endl;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        bfs(a);

        vector<int> path;
        while (b != -1) {
            path.push_back(b);
            b = parent[b];
        }

        reverse(path.begin(), path.end());

        cout << path.size() << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}