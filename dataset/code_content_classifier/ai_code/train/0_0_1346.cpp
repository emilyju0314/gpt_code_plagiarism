#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> adj;
vector<vector<bool>> reachable;
vector<vector<int>> dist;

void bfs(int start, vector<int>& d) {
    d[start] = 0;
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
            if (d[u] == INF) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    adj.resize(n);
    reachable.assign(n, vector<bool>(n, false));
    dist.assign(n, vector<int>(n, INF));
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        reachable[a][b] = reachable[b][a] = true;
    }
    
    vector<int> s1_dist(n, INF), t1_dist(n, INF), s2_dist(n, INF), t2_dist(n, INF);
    int s1, t1, l1, s2, t2, l2;
    
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
    s1--; t1--; s2--; t2--;
    
    bfs(s1, s1_dist);
    bfs(t1, t1_dist);
    bfs(s2, s2_dist);
    bfs(t2, t2_dist);
    
    int ans = m;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!reachable[i][j]) {
                continue;
            }
            
            int cur_path = min(s1_dist[t1], s1_dist[i] + 1 + j + t1_dist[j]);
            cur_path = max(cur_path, min(s2_dist[t2], s2_dist[i] + 1 + j + t2_dist[j]));
            
            if (cur_path > l1 + l2) {
                ans = min(ans, (int)adj[i].size());
            }
        }
    }
    
    cout << (ans == m ? -1 : ans) << endl;
    
    return 0;
}