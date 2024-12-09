#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int fast_max(int n, int k) {
    vector<long long> dp(n + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        
        for (int j = 1; j <= min(i, k); j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    
    long long not_equal_n = 0;
    
    for (int i = 1; i < n; i++) {
        not_equal_n = (not_equal_n + dp[i]) % MOD;
    }
    
    return not_equal_n;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    cout << fast_max(n, k) << endl;
    
    return 0;
}