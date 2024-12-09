#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i-1][j];
            for (int k = 1; k <= j; k++) {
                if (s[i-1] == 'r') {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
                } else {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
                }
            }
        }
    }

    int ans = dp[K][N];
    cout << ans << endl;

    return 0;
}