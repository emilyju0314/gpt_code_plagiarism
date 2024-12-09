#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<vector<int>> dp(N+1, vector<int>(2, 0)); // dp[i][j] denotes number of ways to get to state j using i characters

    dp[0][0] = 1; // Initial state when no characters are used

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i - j >= 0 && j >= A) {
                dp[i][1] = (dp[i][1] + dp[i-j][0]) % MOD; // Replace j characters with 1
            }
            if (i - j >= 0 && j >= B) {
                dp[i][0] = (dp[i][0] + dp[i-j][1]) % MOD; // Replace j characters with 0
            }
        }
    }

    int result = (dp[N][0] + dp[N][1]) % MOD;
    cout << result << endl;

    return 0;
}