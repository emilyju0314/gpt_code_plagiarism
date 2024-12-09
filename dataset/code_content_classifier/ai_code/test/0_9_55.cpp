#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<long long> dp(k + 1);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= k; i++) {
        dp[i] = (dp[i-1] * ((dp[i-1] * 4) % MOD)) % MOD;
    }

    cout << dp[k] << endl;

    return 0;
}