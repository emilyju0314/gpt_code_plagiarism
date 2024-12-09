#include <iostream>
#include <vector>
#include <cstring>
#define MOD 1000000007

using namespace std;

vector<int> tree[100005];
vector<int> query[100005];
int n, q;
int dp[305][100005], cnt[100005], p[100005];

void dfs(int u, int par) {
    dp[1][u] = 1;
    for (int v : tree[u]) {
        if (v == par) continue;
        dfs(v, u);
        for (int i = 2; i <= 300; i++) {
            dp[i][u] = (dp[i][u] + dp[1][v]) % MOD;
            for (int j = 2; j <= i; j++) {
                dp[i][u] = (dp[i][u] + dp[j][v]) % MOD;
            }
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    for (int i = 0; i < q; i++) {
        int k, m, r;
        cin >> k >> m >> r;
        for (int j = 1; j <= k; j++) {
            int v;
            cin >> v;
            query[i].push_back(v);
        }
        
        memset(dp, 0, sizeof(dp));
        dfs(r, 0);
        
        p[0] = 1;
        for (int j = 1; j <= k; j++) {
            p[j] = (p[j-1] * 1LL * dp[1][query[i][j-1]]) % MOD;
        }
        
        for (int j = k; j >= 1; j--) {
            cnt[j] = p[j];
            for (int l = j+1; l <= k; l++) {
                cnt[j] = (cnt[j] - (dp[l-j+1][query[i][l-1]] * 1LL * cnt[l] % MOD) + MOD) % MOD;
            }
        }
        
        int ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + cnt[j]) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}