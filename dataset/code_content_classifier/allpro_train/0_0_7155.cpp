#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[3] = 24;
    dp[4] = 4;

    for (int i = 5; i <= n; i++) {
        dp[i] = (i - 1) * ((dp[i - 1] + dp[i - 2]) % MOD) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}