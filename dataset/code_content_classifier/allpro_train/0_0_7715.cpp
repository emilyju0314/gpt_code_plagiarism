#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

int n;
vector<int> adj[MAXN];
int dp[MAXN][2];
int ans;

void dfs(int u) {
    dp[u][0] = dp[u][1] = 1;
    
    for(int v : adj[u]) {
        dfs(v);
        
        dp[u][1] = (1LL * dp[u][1] * dp[v][1]) % MOD;
        dp[u][1] = (dp[u][1] + 1LL * dp[u][0] * dp[v][1]) % MOD;
        
        dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % MOD;
    }
    
    ans = (ans + dp[u][1]) % MOD;
}

int main() {
    cin >> n;
    
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    
    dfs(1);
    
    cout << ans << endl;
    
    return 0;
}