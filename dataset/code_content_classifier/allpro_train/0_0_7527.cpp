#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    vector<long long> dp(1 << 20, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        vector<long long> new_dp(1 << 20, 0);
        for(int mask = 0; mask < (1 << 20); mask++) {
            if(dp[mask] == 0) continue;
            
            bool valid = true;
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == '?') continue;
                int idx = words[i][j] - 'a';
                if(mask & (1 << idx)) {
                    valid = false;
                    break;
                }
            }
            
            if(!valid) continue;
            
            int new_mask = mask;
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == '?') continue;
                int idx = words[i][j] - 'a';
                new_mask |= (1 << idx);
            }
            
            new_dp[new_mask] += dp[mask];
            new_dp[new_mask] %=  MOD;
        }
        
        dp = new_dp;
    }
    
    long long ans = 0;
    for(int i = 0; i < (1 << 20); i++) {
        ans += dp[i];
        ans %= MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}