#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MOD 1000000007

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int d;
        long long m;
        cin >> d >> m;
        
        vector<long long> dp(d+1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= d; i++) {
            dp[i] = (dp[i-1] * (power(2, i) - 1) % MOD) % MOD;
            dp[i] = (dp[i] + dp[i-1]) % MOD;
        }
        
        long long ans = (dp[d] * power(2, m) % MOD) % MOD;
        ans = (ans - 1 + MOD) % MOD;
        
        cout << ans << endl;
    }
    
    return 0;
}