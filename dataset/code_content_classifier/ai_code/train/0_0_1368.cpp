#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 998244353

int main() {
    int N;
    cin >> N;

    vector<vector<long long>> dp(2, vector<long long>(4, 0)); // dp[i][j] represents the number of strings of length i ending with state j
    dp[2 % 2][0] = 1; // Initialize for length 2

    for (int i = 3; i <= N; ++i) {
        vector<vector<long long>> new_dp(2, vector<long long>(4, 0));
        for (int j = 0; j < 4; ++j) {
            new_dp[i % 2][j] = (new_dp[i % 2][j] + dp[(i - 1) % 2][(j ^ 3)] * 2) % MOD;
            new_dp[i % 2][3] = (new_dp[i % 2][3] + dp[(i - 1) % 2][(j ^ 3)]) % MOD;
            new_dp[i % 2][j] = (new_dp[i % 2][j] + dp[(i - 1) % 2][(j ^ 1)]) % MOD;
            new_dp[i % 2][3] = (new_dp[i % 2][3] + dp[(i - 1) % 2][(j ^ 1)]) % MOD;
        }
        dp[i % 2] = new_dp[i % 2];
    }

    cout << ((dp[N % 2][0] + dp[N % 2][1] + dp[N % 2][2] + dp[N % 2][3]) % MOD) << endl;

    return 0;
}