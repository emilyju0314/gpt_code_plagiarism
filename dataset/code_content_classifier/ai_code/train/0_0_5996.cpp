#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 3e5 + 5;

vector<int> adj[MAXN];
vector<int> asphalt(MAXN);
vector<int> repaired;
vector<bool> visited(MAXN, false);

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                repaired.push_back(v);
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 1; i <= n; i++) {
        cin >> asphalt[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, n);

    long long total_asphalt = 0;
    for (int node : repaired) {
        total_asphalt += asphalt[node];
    }

    if (total_asphalt < 2LL * (long long)(n - 1) * x)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << repaired[i] << endl;
        }
    }

    return 0;
}