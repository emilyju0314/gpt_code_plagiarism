#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i - 1] == h) {
                dp[i][j] = dp[i - 1][j] % MOD;
            } else if(a[i - 1] == h - 1) {
                for(int k = 1; k <= j; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k - 1]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}