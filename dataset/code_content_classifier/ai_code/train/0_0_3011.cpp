#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << endl;

    return 0;
}