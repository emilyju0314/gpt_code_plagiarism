#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, b, k, x;
    cin >> n >> b >> k >> x;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(b + 1, vector<int>(x, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= b; i++) {
        vector<int> cnt(x, 0);
        for (int j = 0; j < n; j++) {
            cnt[a[j] % x]++;
        }

        for (int j = 0; j < x; j++) {
            for (int k = 0; k < x; k++) {
                int new_rem = (j * 10 + k) % x;
                dp[i][new_rem] = (dp[i][new_rem] + 1LL * dp[i - 1][j] * cnt[k]) % MOD;
            }
        }
    }

    cout << dp[b][k] << endl;

    return 0;
}