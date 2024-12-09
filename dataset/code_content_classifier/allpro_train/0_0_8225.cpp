#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int countPalindromicSubsequences(string S) {
    int n = S.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (S[i] == S[j]) {
                dp[i][j] = (2 * dp[i+1][j-1]) % MOD;
                int l = i + 1;
                int r = j - 1;
                while (l <= r && S[i] != S[l]) {
                    l++;
                }
                while (l <= r && S[i] != S[r]) {
                    r--;
                }
                if (l > r) {
                    dp[i][j] = (dp[i][j] + 2) % MOD;
                } else if (l == r) {
                    dp[i][j] = (dp[i][j] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i][j] - dp[l+1][r-1] + MOD) % MOD;
                }
            } else {
                dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + MOD) % MOD;
            }
        }
    }

    return dp[0][n-1];
}

int main() {
    string S;
    cin >> S;

    int result = countPalindromicSubsequences(S);
    
    cout << result << endl;

    return 0;
}