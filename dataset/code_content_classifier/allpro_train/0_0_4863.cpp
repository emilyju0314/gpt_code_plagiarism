#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> restStops;

bool dfs(int u, int parent, int k, int dest) {
    if (u == dest) {
        return true;
    }
    for (int v : adj[u]) {
        if (v != parent) {
            if (find(restStops.begin(), restStops.end(), v) == restStops.end() && k == 0) {
                continue;
            }
            if (dfs(v, u, (find(restStops.begin(), restStops.end(), v) != restStops.end() ? k : k - 1), dest)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, k, r;
    cin >> n >> k >> r;
    
    adj.resize(n+1);
    
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    restStops.resize(r);
    
    for (int i = 0; i < r; i++) {
        cin >> restStops[i];
    }
    
    int v;
    cin >> v;
    
    for (int i = 0; i < v; i++) {
        int start, dest;
        cin >> start >> dest;
        
        if (dfs(start, -1, k, dest)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}