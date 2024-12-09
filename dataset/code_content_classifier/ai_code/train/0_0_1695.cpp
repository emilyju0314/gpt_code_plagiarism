#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;

vector<int> adj[105];
int n, k;
int dp[105][25][2];

int dfs(int u, int parent, int dist, bool isParentBlack) {
    int &res = dp[u][dist][isParentBlack];
    
    if(res != -1) {
        return res;
    }
    
    if(dist > k) {
        return res = 0;
    }
    
    if(adj[u].size() == 1 && adj[u][0] == parent) {
        return res = 1;
    }
    
    res = 1;
    for(int v : adj[u]) {
        if(v == parent) {
            continue;
        }
        
        res = (res * (dfs(v, u, 1, true) + dfs(v, u, dist + 1, false))) % MOD;
    }
    
    return res;
}

int main() {
    cin >> n >> k;
    
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(dp, -1, sizeof(dp));
    
    int ans = (dfs(1, 0, 1, true) + dfs(1, 0, 1, false)) % MOD;
    cout << ans << endl;
    
    return 0;
}