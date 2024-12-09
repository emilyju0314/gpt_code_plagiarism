#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int k;
    cin >> k;

    vector<long long> dp(k+1, 0);
    dp[1] = 6;

    for(int i = 2; i <= k; i++) {
        dp[i] = (dp[i-1] * 3) % MOD;
    }

    long long ans = 1;
    for(int i = 1; i <= k; i++) {
        ans = (ans * dp[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}