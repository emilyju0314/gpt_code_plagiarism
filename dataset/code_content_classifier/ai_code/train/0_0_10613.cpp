#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 300005;

int n, q;
vector<int> adj[MAXN];
int sz[MAXN];
int centroid[MAXN];

void dfs(int u, int p) {
    sz[u] = 1;
    bool is_centroid = true;
    
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (sz[v] > n / 2) {
                is_centroid = false;
            }
        }
    }
    
    if (n - sz[u] > n / 2) {
        is_centroid = false;
    }
    
    if (is_centroid) {
        centroid[u] = 1;
    }
}

int main() {
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        adj[parent].push_back(i);
    }
    
    dfs(1, 0);
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << centroid[query] << endl;
    }
    
    return 0;
}