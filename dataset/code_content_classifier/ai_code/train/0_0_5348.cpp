#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

int countIntegers(string num, int D) {
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(D, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            for (int x = 0; x <= (num[i] - '0'); x++) {
                dp[i + 1][(j + x) % D] += dp[i][j];
                dp[i + 1][(j + x) % D] %= MOD;
            }
        }
    }

    return (dp[n][0] - 1 + MOD) % MOD;
}

int main() {
    string K;
    int D;
    cin >> K >> D;

    int ans = countIntegers(K, D);
    cout << ans << endl;

    return 0;
}