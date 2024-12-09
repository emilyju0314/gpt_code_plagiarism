#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> special(n + 1, false);
    for (int i = 0; i < k; i++) {
        int s;
        cin >> s;
        special[s] = true;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int max_dist = dist[n];
    
    int max_extra_dist = 0;
    for (int i = 1; i <= n; i++) {
        if (!special[i]) continue;
        
        for (int v : adj[i]) {
            if (!special[v]) {
                int extra_dist = dist[i] + dist[v] + 1;
                max_extra_dist = max(max_extra_dist, extra_dist);
            }
        }
    }

    cout << max(max_dist, max_extra_dist) << endl;

    return 0;
}