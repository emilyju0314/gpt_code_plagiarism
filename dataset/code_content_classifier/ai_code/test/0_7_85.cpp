#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    dp[1][1] = 1;

    for (int i = 2; i <= n + 1; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] = (dp[i][j] + (dp[i - j][k] * dp[j][j]) % MOD) % MOD;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 1; i < n + 1; i++) {
        ans = (ans + dp[n + 1][i]) % MOD;
    }

    cout << power(ans, m) << endl;

    return 0;
}