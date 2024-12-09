#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    if(a > b) {
        swap(a, b);
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n * (b - a) + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i * (b - a); j++) {
            for(int k = a; k <= b; k++) {
                if(j - k >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i <= n * (b - a); i++) {
        ans = (ans + dp[n][i] * dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}