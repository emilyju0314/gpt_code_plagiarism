#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<long long> dp(k + 1, 0);
    dp[1] = 6; // Base case for the root node

    for (int i = 2; i <= k; i++) {
        dp[i] = (3 * dp[i - 1] % MOD) * (dp[i - 1] % MOD) % MOD;
    }

    cout << dp[k] << endl;

    return 0;
}