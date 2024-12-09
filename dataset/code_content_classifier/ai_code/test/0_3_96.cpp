#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    vector<long long> dp(x + 1);
    dp[1] = 1;

    for(int i = 2; i <= x; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k < i; k++) {
                dp[i] = (dp[i] + dp[k] * dp[i - k]) % MOD;
            }
        }
    }

    cout << dp[x] << endl;

    return 0;
}