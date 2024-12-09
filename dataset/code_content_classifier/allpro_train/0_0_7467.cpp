#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> dp(k + 1, 0);
        dp[1] = 1;
        
        for(int i = 0; i < n; i++) {
            vector<long long> new_dp(k + 1, 0);
            for(int j = 1; j <= k; j++) {
                new_dp[j] = (new_dp[j] + dp[j]) % MOD;
                if(j < k) {
                    new_dp[j + 1] = (new_dp[j + 1] + dp[j]) % MOD;
                }
            }
            dp = new_dp;
        }
        
        long long ans = 0;
        for(int j = 1; j <= k; j++) {
            ans = (ans + dp[j]) % MOD;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}