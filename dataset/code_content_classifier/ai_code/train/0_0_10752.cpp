#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> answers(n);
    for(int i = 0; i < n; i++) {
        cin >> answers[i];
    }

    vector<int> dp(k+1);
    dp[0] = 1;

    for(int i = 0; i < n; i++) {
        vector<int> new_dp(k+1);

        for(int j = 0; j <= k; j++) {
            new_dp[j] = (2*dp[j]) % MOD;
        }

        for(int j = 0; j < k; j++) {
            new_dp[j+1] = (new_dp[j+1] + dp[j]) % MOD;
        }

        dp = new_dp;
    }

    int count = 0;
    for(int i = 0; i < k; i++) {
        if(i + 1 != answers[0]) {
            count = (count + dp[i]) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}