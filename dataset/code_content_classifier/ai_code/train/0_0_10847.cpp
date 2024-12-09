#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int n;
int a[MAXN];
vector<int> adj[MAXN];
set<int> values[MAXN];

void dfs(int u, int p) {
    values[u].insert(a[u]);
    
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            for(int val : values[v]) {
                values[u].insert(val);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(values[i].size() == n) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}