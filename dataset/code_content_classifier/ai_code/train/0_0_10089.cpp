#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string p;
    cin >> p;
    
    vector<int> positions(m);
    for(int i = 0; i < m; i++) {
        cin >> positions[i];
    }
    
    int p_len = p.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    
    vector<long long> prefix_sum(n + 1);
    
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        for(int j = 0; j < m; j++) {
            if(i >= p_len + positions[j]) {
                dp[i] += prefix_sum[i - p_len - positions[j]];
            }
        }
        
        dp[i] %= MOD;
        prefix_sum[i] = (prefix_sum[i-1] + dp[i]) % MOD;
    }
    
    long long ans = 0;
    for(int i = n-p_len+1; i <= n; i++) {
        ans += dp[i];
    }
    
    cout << ans % MOD << endl;
    
    return 0;
}