#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int k, n;
    cin >> k >> n;

    unordered_map<int, string> colors;
    for(int i = 0; i < n; i++) {
        int v;
        string s;
        cin >> v >> s;
        colors[v] = s;
    }

    vector<vector<vector<int>>> dp(2<<k, vector<vector<int>>(n+1, vector<int>(64, 0)));
    dp[1][colors[1] != "" ? 1 : 0][1] = 1;

    for(int i = 2; i < (1<<k); i++) {
        if(colors[i] != "") {
            for(int j = 0; j <= n; j++) {
                for(int mask = 1; mask < 64; mask++) {
                    if(dp[i/2][j][mask] > 0) {
                        if((colors[i] == "white" && (mask & 3) != 0) ||
                           (colors[i] == "yellow" && (mask & 12) != 0) ||
                           (colors[i] == "green" && (mask & 9) != 0) ||
                           (colors[i] == "blue" && (mask & 6) != 0) ||
                           (colors[i] == "red" && (mask & 33) != 0) ||
                           (colors[i] == "orange" && (mask & 24) != 0)) {
                            dp[i][j+1][mask] = (dp[i][j+1][mask] + dp[i/2][j][mask]) % MOD;
                        }
                    }
                }
            }
        } else {
            for(int j = 0; j <= n; j++) {
                for(int mask = 1; mask < 64; mask++) {
                    if(dp[i/2][j][mask] > 0) {
                        for(int newMask = 1; newMask < 64; newMask++) {
                            if((newMask & mask) == 0) {
                                if((mask & 3) != 0 || (newMask & 3) != 0) {
                                    if((mask & 12) != 0 || (newMask & 12) != 0) {
                                        if((mask & 9) != 0 || (newMask & 9) != 0) {
                                            if((mask & 6) != 0 || (newMask & 6) != 0) {
                                                if((mask & 33) != 0 || (newMask & 33) != 0) {
                                                    if((mask & 24) != 0 || (newMask & 24) != 0) {
                                                        dp[i][j][newMask] = (dp[i][j][newMask] + dp[i/2][j][mask]) % MOD;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= n; j++) {
        for(int mask = 1; mask < 64; mask++) {
            ans = (ans + dp[(1<<k)-1][j][mask]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}