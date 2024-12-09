#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    // dp[i][j] represents the number of ways to choose initial health points for i heroes
    // such that there is no winner and the maximum initial health point is j
    vector<vector<int>> dp(n+1, vector<int>(x+1));

    for(int i = 1; i <= x; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            for(int k = 1; k <= j/2; k++) {
                dp[i][j] = (dp[i][j] + (dp[i-1][k] * dp[i-1][j-k]) % MOD) % MOD;
            }
        }
    }

    int total_ways = 0;
    for(int i = 1; i <= x; i++) {
        total_ways = (total_ways + dp[n][i]) % MOD;
    }

    cout << total_ways << endl;

    return 0;
}