#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000003;

int solve(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i += 2) {
        dp[i][i] = 1;
    }

    for (int l = 2; l <= n; l += 2) {
        for (int i = 0; i < n - l + 1; i += 2) {
            int j = i + l - 1;
            for (int k = i + 1; k < j; k += 2) {
                if (s[k] == '+' || s[k] == '-' || s[k] == '*' || s[k] == '/') {
                   // Check if the sub-expressions around the operator are valid
                    if ((s[i] >= '0' && s[i] <= '9') && (s[k - 1] == '+' || s[k - 1] == '-' || s[k - 1] == '*' || s[k - 1] == '/')) {
                        dp[i][j] = (dp[i][j] + dp[i][k - 1] * dp[k + 1][j]) % MOD;
                    }
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;

    int result = solve(s);
    cout << result << endl;

    return 0;
}