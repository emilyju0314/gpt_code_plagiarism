#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countPairs(int s) {
    vector<vector<long long>> dp(10, vector<long long>(s+1));
    dp[0][0] = 1;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= s; j++) {
            for (int k = 0; k <= i && k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
            }
        }
    }
    return dp[9][s];
}

int main() {
    int S;
    cin >> S;
    cout << countPairs(S) << endl;
    return 0;
}