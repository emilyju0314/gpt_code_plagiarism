#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 998244353
#define MAXN 500005

using namespace std;

int t, n;
int a[MAXN];
int dp[MAXN][3];

int solve() {
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            dp[i][0] = (1 + dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            if(a[i] == 1) {
                dp[i][1] = (dp[i][0] + dp[i-1][1]) % MOD;
            } else if (a[i] == 2) {
                dp[i][2] = (dp[i][1] + dp[i-1][2]) % MOD;
            }
        }
    }

    return (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
}

int main() {
    cin >> t;

    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        cout << solve() << endl;
    }

    return 0;
}