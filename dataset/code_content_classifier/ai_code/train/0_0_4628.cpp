#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    vector<int> dp(n+1, 0);
    dp[a] = 1;

    for(int i = 0; i < k; i++) {
        vector<int> new_dp(n+1, 0);
        for(int j = 1; j <= n; j++) {
            if(j == b) continue;
            int sum = 0;
            for(int m = 1; m <= n; m++) {
                if(m != j) {
                    if(abs(a-j) < abs(a-b) && abs(j-m) < abs(j-b)) {
                        sum += dp[m];
                        sum %= MOD;
                    }
                }
            }
            new_dp[j] = sum;
        }
        dp = new_dp;
    }

    int answer = 0;
    for(int i = 1; i <= n; i++) {
        answer = (answer + dp[i]) % MOD;
    }

    cout << answer << endl;

    return 0;
}