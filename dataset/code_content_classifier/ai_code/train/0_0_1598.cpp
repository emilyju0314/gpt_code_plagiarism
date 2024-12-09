#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
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
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int main1, main2;
        cin >> main1 >> main2;
        
        for (int j = 1; j <= n; j++) {
            dist[j] = -1;
        }
        
        bfs(main1);
        
        int ans = dist[main2];
        
        cout << ans << endl;
    }
    
    return 0;
}