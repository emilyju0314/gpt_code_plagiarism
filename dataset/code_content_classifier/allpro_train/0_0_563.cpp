#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int a, b, k, t;
    cin >> a >> b >> k >> t;

    vector<vector<int>> dp(t + 1, vector<int>((2*k + 1)*t + 1, 0));
    dp[0][(b-a) + k*t] = 1; // Initial position

    for(int i = 1; i <= t; i++) {
        for(int j = 0; j <= (2*k + 1)*t; j++) {
            for(int d = -k; d <= k; d++) {
                if(j+d >= 0 && j+d <= (2*k + 1)*t) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+d]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int j = (k*t) + 1; j <= (2*k + 1)*t; j++) {
        ans = (ans + dp[t][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}