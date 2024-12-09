#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> dist;

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
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> affected(m);
    for (int i = 0; i < m; i++) {
        cin >> affected[i];
    }

    adj.resize(n + 1);
    dist.assign(n + 1, -1);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(affected[0]);

    int max_dist = 0;
    int max_idx = affected[0];
    for (int i = 1; i < m; i++) {
        if (dist[affected[i]] > max_dist) {
            max_dist = dist[affected[i]];
            max_idx = affected[i];
        }
    }

    dist.assign(n + 1, -1);
    bfs(max_idx);

    int cnt = count_if(dist.begin() + 1, dist.end(), [d](int x){ return x <= d; });

    cout << cnt << endl;

    return 0;
}