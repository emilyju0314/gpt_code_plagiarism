#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 998244353
#define MAXN 405

int n, m;
vector<int> adj[MAXN];
int dp[MAXN][MAXN];

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            
            for (int u : adj[i]) {
                for (int v : adj[j]) {
                    if (u != v) {
                        dp[i][j] = (dp[i][j] + dp[u][v]) % MOD;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}