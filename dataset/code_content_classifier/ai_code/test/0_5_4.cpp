#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

using namespace std;

vector<vector<pair<int, int>>> adj; // adjacency list
vector<int> a; // happiness values of attractions
long long total_happiness;

int dfs(int u, int p, int k) {
    vector<long long> subpaths;
    for (auto edge : adj[u]) {
        int v = edge.first;
        if (v == p) continue;
        int color = edge.second;
        long long val = dfs(v, u, k);
        if (val == -1) return -1;
        if (color || k) subpaths.push_back(max(val, 0LL));
        else subpaths.push_back(val + a[v]);
    }
    sort(subpaths.begin(), subpaths.end(), greater<long long>());
    long long ans = subpaths[0];
    if (subpaths.size() > 1) ans = max(ans, 0LL) + max(subpaths[1], 0LL);
    total_happiness = (total_happiness + max(ans, 0LL)) % MOD;
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        u--; v--;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    
    total_happiness = 0;
    dfs(0, -1, k);
    
    cout << total_happiness << endl;

    return 0;
}