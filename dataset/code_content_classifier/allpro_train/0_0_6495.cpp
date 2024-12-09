#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(N, -1);
    
    queue<int> q;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        dist.assign(N, -1);
        q.push(a);
        dist[a] = 0;
        
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
        
        cout << dist[b] << endl;
    }
    
    return 0;
}