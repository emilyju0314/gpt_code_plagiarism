#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for(int i = 0; i < n; i++) {
        vector<int> vis(n);
        dist[i][i] = prices[i];
        vis[i] = 1;
        for(int j : adj[i]) {
            dist[i][j] = min(dist[i][j], prices[i]);
        }
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            for(int k : adj[j]) {
                if(vis[k]) {
                    dist[i][j] = min(dist[i][j], prices[i]);
                }
            }
        }
    }
    
    for(int i = 0; i < q; i++) {
        char type;
        int a, b;
        cin >> type >> a >> b;
        a--; b--;
        
        if(type == 'C') {
            prices[a] = b;
            for(int j : adj[a]) {
                dist[j][a] = prices[a];
            }
            dist[a][a] = b;
        } else {
            cout << dist[a][b] << endl;
        }
    }
    
    return 0;
}