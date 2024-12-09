#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int dfs(int v, int p, vector<vector<int>>& dp, vector<vector<int>>& children, vector<int>& child_count) {
    dp[v][0] = 1;
    for (int u : children[v]) {
        if (u == p) continue;
        child_count[v]++;
        int res = dfs(u, v, dp, children, child_count);
        vector<int> tmp(child_count[v] + child_count[u] + 1);
        
        for (int i = 0; i <= child_count[v]; i++) {
            for (int j = 0; j <= child_count[u]; j++) {
                tmp[i + j] = (tmp[i + j] + 1LL * dp[v][i] * dp[u][j]) % MOD;
                if (j > 0) {
                    tmp[i + j - 1] = (tmp[i + j - 1] + 1LL * dp[v][i] * dp[u][j]) % MOD;
                }
            }
        }
        
        dp[v] = tmp;
    }
    
    return dp[v][0];
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> dp(N, vector<int>(N, 0));
    vector<vector<int>> children(N);
    vector<int> child_count(N, 0);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        children[a].push_back(b);
        children[b].push_back(a);
    }
    
    dfs(0, -1, dp, children, child_count);
    
    cout << dp[0][0] << endl;
    
    return 0;
}