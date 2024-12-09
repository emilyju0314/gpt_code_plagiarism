#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1e5+5;

vector<int> adj[MAXN];
int values[MAXN];
int parent[MAXN];
int subtree_size[MAXN];
int subtree_sum[MAXN];

void dfs(int v, int p) {
    parent[v] = p;
    subtree_size[v] = 1;
    
    for(int u : adj[v]) {
        if(u != p) {
            dfs(u, v);
            subtree_size[v] += subtree_size[u];
        }
    }
}

void update_subtree(int u, int v, int x) {
    while(u != v) {
        subtree_sum[u] += x;
        u = parent[u];
    }
    subtree_sum[v] += x;
}

int query_subtree_sum(int v) {
    int sum = subtree_sum[v];
    int u = parent[v];
    
    while(u != 0) {
        sum += subtree_sum[u];
        u = parent[u];
    }
    
    return sum;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int v;
            cin >> v;
            dfs(v, 0);
        } else if(type == 2) {
            int u, v, x;
            cin >> u >> v >> x;
            update_subtree(u, v, x);
        } else {
            int v;
            cin >> v;
            cout << query_subtree_sum(v) + values[v] << endl;
        }
    }
    
    return 0;
}