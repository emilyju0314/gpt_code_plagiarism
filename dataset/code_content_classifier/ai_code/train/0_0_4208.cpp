#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<int> a(MAXN), ans(MAXN), cnt(MAXN), sum(MAXN);

void dfs(int v, int p) {
    sum[v] = a[v];
    cnt[v] = 1;
    
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        sum[v] += max(0, sum[u] - a[u]);
        cnt[v] += cnt[u];
    }
    
    ans[v] = cnt[v] - 1 - (sum[v] <= a[v]);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        adj[p].push_back(i+1);
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}