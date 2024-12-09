#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    int x;
    cin >> s >> x;

    int n = s.length();

    vector<vector<int>> prefix_sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        int digit = s[i - 1] - '0';
        for (int j = i; j <= n; j++) {
            prefix_sum[i][j] = prefix_sum[i][j - 1] + digit;
            digit = s[j] - '0';
        }
    }

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int sum = prefix_sum[j + 1][i];
            if (sum == x) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
            for (int k = j + 1; k < i; k++) {
                if (sum % prefix_sum[j + 1][k] == 0) {
                    sum = 0;
                    break;
                }
            }
            if (sum == 0) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << (dp[n] == 1e9 ? 0 : dp[n]) << endl;

    return 0;
}