#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> dist;

int ask(int u, int v) {
    cout << "? " << u << " " << v << endl;
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
}

void dfs(int v, int p, int d) {
    dist[v] = d;
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d+1);
        }
    }
}

int main() {
    cin >> n;
    
    adj.resize(n+1);
    dist.assign(n+1, -1);
    
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int u = 1;
    int v = 1;
    int w = ask(u, v);
    
    while (dist[w] == -1) {
        dfs(u, -1, 0);
        int x = max_element(dist.begin(), dist.end()) - dist.begin();
        dist.assign(n+1, -1);
        w = ask(w, x);
    }
    
    cout << "! " << w << endl;
    cout.flush();
    
    return 0;
}