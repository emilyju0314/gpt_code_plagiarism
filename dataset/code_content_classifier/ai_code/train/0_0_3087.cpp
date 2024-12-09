#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, s, t;
vector<vector<int>> adj;
vector<int> dist_s, dist_t;

void bfs(int start, vector<int>& dist) {
    dist.assign(n+1, -1);
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
    cin >> n >> m >> s >> t;

    adj.resize(n+1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(s, dist_s);
    bfs(t, dist_t);

    int max_dist = dist_s[t];

    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            if (dist_s[i] + 1 + dist_t[j] >= max_dist && dist_s[j] + 1 + dist_t[i] >= max_dist) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}