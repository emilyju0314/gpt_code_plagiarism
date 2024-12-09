#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 998244353;

vector<vector<int>> adj;
vector<vector<long long>> dp;

void dfs(int u, int parent) {
    dp[u][0] = dp[u][1] = 1;
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        
        dfs(v, u);
        
        dp[u][0] = (dp[u][0] * (dp[v][0] + dp[v][1])) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
}

int main() {
    int n;
    cin >> n;
    
    adj.resize(n+1);
    dp.resize(n+1, vector<long long>(2));
    
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1, 0);
    
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    
    return 0;
}