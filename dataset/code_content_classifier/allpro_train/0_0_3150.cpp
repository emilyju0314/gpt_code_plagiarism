#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(20010, 0));
    dp[0][10000 + a[0]] = 1;
    dp[0][10000 - a[0]] = 1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 20010; j++) {
            if(j - a[i] >= 0) {
                dp[i][j] += dp[i-1][j - a[i]];
            }
            if(j + a[i] < 20010) {
                dp[i][j] += dp[i-1][j + a[i]];
            }
            dp[i][j] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < 20010; i++) {
        ans += dp[n-1][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}