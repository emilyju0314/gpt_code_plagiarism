#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int power(int x, int y) {
    int res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x) % MOD;
        y = y / 2;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;
        
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        vector<long long> dp(5e7 + 5, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            vector<long long> new_dp(5e7 + 5, 0);
            for (int j = 0; j < k; j++) {
                new_dp[j] = (new_dp[j] + dp[j]) % MOD;
                new_dp[j ^ x] = (new_dp[j ^ x] + dp[j]) % MOD;
            }
            swap(dp, new_dp);
        }
        
        long long ans = power(2, n) - dp[0];
        if (ans < 0) ans += MOD;
        
        cout << ans << endl;
    }
    
    return 0;
}