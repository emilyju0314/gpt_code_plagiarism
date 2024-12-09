#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    // dp[i][j] represents the number of ways to connect the first i towns such that the last town has j roads connected to it
    vector<vector<long long>> dp(n+1, vector<long long>(4, 0));
    dp[1][d[0]] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= 3; j++) {
            for (int k = 2; k <= 3; k++) {
                if (j + k <= 3) {
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 2; j <= 3; j++) {
        ans += dp[n][j];
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}