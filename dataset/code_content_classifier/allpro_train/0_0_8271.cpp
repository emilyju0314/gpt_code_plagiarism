#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    vector<vector<long long>> dp(n+1, vector<long long>(m, 0));
    for (char c : s) {
        vector<long long> new_dp(m, 0);
        if (c == s[0]) {
            if (n > 1) {
                dp[1][c - 'a'] = 1;
            } else {
                cout << 1 << endl;
                return 0;
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == j + 'a') {
                for (int k = 0; k < m; k++) {
                    if (abs(j - k) > 1) {
                        dp[i+1][j] += dp[i][k];
                        dp[i+1][j] %= 1000000007;
                    }
                }
            }
        }
    }
    
    long long ans = 0;
    for (int j = 0; j < m; j++) {
        ans += dp[n][j];
        ans %= 1000000007;
    }
    
    cout << ans << endl;
    
    return 0;
}