#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 55;
const int MAXMOD = 1000000000;

int main() {
    int n, mod;
    cin >> n >> mod;

    vector<vector<long long>> dp(n+1, vector<long long>(n*(n-1)/2+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i*(i-1)/2; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= n*(n-1)/2; ++i) {
        ans = (ans + ((dp[n][i] * i) % mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}