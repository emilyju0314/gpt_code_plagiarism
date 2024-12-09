#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> volunteers(k);
    for(int i = 0; i < k; i++) {
        cin >> volunteers[i];
    }

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist(n+1, INF);
    vector<bool> vis(n+1, false);

    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        vis[curr] = true;

        for(int neighbor : adj[curr]) {
            if(!vis[neighbor] && dist[curr]+1 < dist[neighbor]) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    if(dist[t] == INF) {
        cout << -1 << endl;
        return 0;
    }

    int min_q = INF;
    for(int volunteer : volunteers) {
        if(dist[volunteer] < dist[t]) {
            min_q = min(min_q, dist[volunteer]);
        }
    }

    cout << min_q << endl;

    return 0;
}