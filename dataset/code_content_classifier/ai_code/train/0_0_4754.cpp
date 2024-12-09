#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    
    vector<int> weights(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> weights[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        
        if (t == 1) {
            weights[a] = b;
        } else if (t == 2) {
            vector<int> dist(n + 1, -1);
            dist[a] = 0;
            vector<int> q = {a};

            while (!q.empty()) {
                int u = q.back();
                q.pop_back();
                
                for (int v : adjList[u]) {
                    if (dist[v] == -1) {  // not visited
                        dist[v] = dist[u] + 1;
                        q.push_back(v);
                    }
                }
            }
            
            int maxWeight = -1;
            for (int i = 1; i <= n; i++) {
                if (dist[i] == b) {
                    maxWeight = max(maxWeight, weights[i]);
                }
            }
            
            cout << maxWeight << endl;
        }
    }
    
    return 0;
}