#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 2005;
const int MAXK = 105;

int dp[MAXN][MAXN][1 << 10];
int n, k;
vector<int> b;

int dfs(int pos, int mex, int mask) {
    if (pos == n) {
        return (mex <= 0 && 0 <= mex + k);
    }
    
    if (dp[pos][mex][mask] != -1) {
        return dp[pos][mex][mask];
    }
    
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int new_mex = max(0, i - mex);
        if (new_mex > k) continue;
        
        int new_mask = mask | (1 << i);
        ans = (ans + dfs(pos + 1, new_mex, new_mask)) % MOD;
    }
    
    return dp[pos][mex][mask] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dfs(1, abs(b[0]-i), 1 << i)) % MOD;
    }

    cout << ans << endl;

    return 0;
}