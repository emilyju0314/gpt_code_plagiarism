#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAXN = 100005;

int N, K;
vector<int> adj[MAXN];
int dp[MAXN][305][2];

void dfs(int u, int p) {
    dp[u][0][0] = dp[u][1][1] = 1;
    
    for (int v : adj[u]) {
        if (v == p) continue;
        
        dfs(v, u);
        
        for (int i = K; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[u][i][0] = (dp[u][i][0] + dp[u][i - j][0] * dp[v][j][0] % MOD) % MOD;
            }
        }
        
        for (int i = K; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[u][i][1] = (dp[u][i][1] + dp[u][i - j][1] * dp[v][j][0] % MOD + dp[u][i - j][0] * dp[v][j][1] % MOD) % MOD;
            }
        }
    }
}

int main() {
    cin >> N >> K;
    
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cout << (dp[1][K][1] + MOD) % MOD << endl;
    
    return 0;
}