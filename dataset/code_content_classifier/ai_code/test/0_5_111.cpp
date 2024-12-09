#include <iostream>
#include <vector>
#include <cstring>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int dp[2][2 * 2005][105];
    memset(dp, 0, sizeof(dp));
    dp[0][2005][0] = 1;

    for (int i = 0; i < n; i++) {
        memset(dp[(i + 1) % 2], 0, sizeof(dp[(i + 1) % 2]));
        for (int sum = 0; sum <= 2 * n; sum++) {
            for (int val = 0; val <= k; val++) {
                if (dp[i % 2][sum][val] == 0) continue;
                for (int t = 0; t <= min(2, n - sum); t++) {
                    for (int add = 0; add <= k; add++) {
                        int nsum = sum + t;
                        int nval = max(val, abs(t + b[i]) - add);
                        if (nval <= k) {
                            dp[(i + 1) % 2][nsum][nval] = (dp[(i + 1) % 2][nsum][nval] + dp[i % 2][sum][val]) % MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int sum = 2005; sum <= 2005 + n; sum++) {
        for (int val = 0; val <= k; val++) {
            ans = (ans + dp[n % 2][sum][val]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}