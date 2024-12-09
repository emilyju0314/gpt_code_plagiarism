#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}