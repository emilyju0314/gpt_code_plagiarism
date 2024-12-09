#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;
const int MAXN = 505;

vector<pair<int, int>> adj[MAXN];
int color[MAXN], dist_black[MAXN];

void dijkstra(int source, int n) {
    for(int i = 1; i <= n; i++) {
        dist_black[i] = INF;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(dist_black[u] < d) continue;
        
        for(auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if(dist_black[v] > d + w) {
                dist_black[v] = d + w;
                pq.push({dist_black[v], v});
            }
        }
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int ans = INF;
    
    for(int source = 1; source <= n; source++) {
        if(color[source] == 1) {
            dijkstra(source, n);
            
            bool is_valid = true;
            for(int v = 1; v <= n; v++) {
                if(color[v] == 0 && dist_black[v] <= x) {
                    is_valid = false;
                    break;
                }
            }
            
            if(is_valid) {
                int cnt = 0;
                for(int v = 1; v <= n; v++) {
                    if(color[v] == 1 && dist_black[v] <= x) {
                        cnt++;
                    }
                }
                ans = min(ans, cnt);
            }
        }
    }
    
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}