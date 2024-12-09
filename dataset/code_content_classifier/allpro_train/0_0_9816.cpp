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
        dp[i] = (dp[i-1] + dp[i-2])*(2*i-1)%MOD;
    }

    cout << dp[n] << endl;

    return 0;
}