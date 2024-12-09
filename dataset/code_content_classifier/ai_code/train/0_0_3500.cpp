#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int dp[n+1][k+1];
    for(int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    for(int i = 2; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[j][i] = 0;
            for(int l = j; l <= n; l += j) {
                dp[j][i] = (dp[j][i] + dp[l][i-1]) % MOD;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++) {
        answer = (answer + dp[i][k]) % MOD;
    }

    cout << answer << endl;

    return 0;
}