#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, T;
    cin >> n >> T;
    
    vector<pair<int, int>> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i].first >> songs[i].second;
    }
    
    vector<vector<vector<int>>> dp(T+1, vector<vector<int>>(n+1, vector<int>(1 << 3)));
    dp[0][0][0] = 1;
    
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << 3); mask++) {
                if (dp[t][i][mask] == 0) continue;
                
                // Transition to next song
                dp[t+songs[i].first][i+1][mask | (1 << songs[i].second-1)] = (dp[t+songs[i].first][i+1][mask | (1 << songs[i].second-1)] + dp[t][i][mask]) % MOD;
                
                // Skip this song
                dp[t][i+1][mask] = (dp[t][i+1][mask] + dp[t][i][mask]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int mask = 0; mask < (1 << 3); mask++) {
        if (__builtin_popcount(mask) == 3) {
            ans = (ans + dp[T][n][mask]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}