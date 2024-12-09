#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int n, m;
long long dp[2022][2][8];

int main() {
    cin >> n >> m;

    dp[0][0][0] = 1;
    dp[0][1][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            for (int cnt = 0; cnt < 8; cnt++) {
                if (dp[i - 1][mask][cnt]) {
                    for (int newMask = 0; newMask < (1 << m); newMask++) {
                        int newCnt = cnt + ((newMask & mask) == 0);
                        if (newCnt <= 3) {
                            dp[i][newMask][newCnt] += dp[i - 1][mask][cnt];
                            dp[i][newMask][newCnt] %= MOD;
                        }
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        for (int cnt = 0; cnt < 4; cnt++) {
            ans += dp[n][mask][cnt];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}