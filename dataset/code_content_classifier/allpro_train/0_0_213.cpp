#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 400005;

vector<int> adj[MAXN];
int subtree[MAXN];
int max_subtree[MAXN];
bool centroid[MAXN];

void dfs(int u, int p) {
    subtree[u] = 1;
    max_subtree[u] = 0;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            subtree[u] += subtree[v];
            max_subtree[u] = max(max_subtree[u], subtree[v]);
        }
    }
}

void update(int u, int p, int n, int max_child) {
    int max_size = max(n - subtree[u], max_child);
    if(max_size <= n/2) {
        centroid[u] = true;
    }
    for(int v : adj[u]) {
        if(v != p) {
            update(v, u, n, max(max_child, subtree[u]-subtree[v]));
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    update(1, 0, n, 0);

    for(int i = 1; i <= n; i++) {
        cout << centroid[i] << " ";
    }
    cout << endl;

    return 0;
}