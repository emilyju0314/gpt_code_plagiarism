#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    string initial;
    cin >> n >> initial;

    vector<long long> dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        // Count the number of different configurations after i attacks
        vector<int> cnt(26, 0);
        for(int j = i-1; j >= 0; j--) {
            cnt[initial[j] - 'a']++;
            if(cnt[initial[j] - 'a'] == 1) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}