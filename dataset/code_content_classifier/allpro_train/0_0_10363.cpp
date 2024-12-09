#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, k;
        cin >> n >> k;

        vector<long long> dp(n+1, 0);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            dp[i] = 1;
            long long sum = 1;
            for(int j = 1; j <= min(i, k); j++) {
                sum = (sum + dp[i-j]) % MOD;
            }
            dp[i] = (dp[i] + sum * 500000004) % MOD;
        }

        cout << dp[n] << endl;
    }

    return 0;
}