#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> subtree_sizes;
int n, k;
int res = 0;

void dfs(int u, int p) {
    subtree_sizes[u] = 1;
    vector<int> sizes;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        subtree_sizes[u] += subtree_sizes[v];
        sizes.push_back(subtree_sizes[v]);
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    int cur = 1;
    for (int size : sizes) {
        res = max(res, cur + size - 1);
        cur = max(cur, min(size, k) + 1);
    }
}

int main() {
    cin >> n >> k;
    adj.resize(n);
    subtree_sizes.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0, -1);

    cout << min(res, k) << endl;

    return 0;
}