#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (3 * dp[i-1]) % MOD; // Every vertex can have 3 edges attached

        for (int j = 1; j <= i - 1; j++) {
            dp[i] = (dp[i] + 2 * dp[i-j-1] * dp[j]) % MOD; // Add the number of ways to create Hagh trees with a size of j and i-j-1
        }
    }

    cout << dp[n] << endl;

    return 0;
}