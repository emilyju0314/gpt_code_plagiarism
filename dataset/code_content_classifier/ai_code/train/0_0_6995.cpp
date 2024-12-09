#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;
    
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<long long>> dp(N + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j < n && s[j] == '0') {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            } else if (j > 0 && s[j - 1] == '1') {
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
            }
        }
    }

    cout << dp[N][n] << endl;

    return 0;
}