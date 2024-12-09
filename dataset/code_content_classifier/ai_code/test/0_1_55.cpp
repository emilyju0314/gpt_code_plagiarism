#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int k;
    cin >> k;

    vector<long long> dp(k+1, 1);
    for(int i = 2; i <= k; i++) {
        dp[i] = (3 * dp[i-1] % MOD * dp[i-1] % MOD) % MOD;
    }

    long long ans = dp[k];
    for(int i = 1; i <= k; i++) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}