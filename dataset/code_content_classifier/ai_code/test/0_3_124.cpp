#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        string s, e;
        cin >> s >> e;
        
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1];
            
            if(s[i - 1] == '0' || s[i - 1] == '?') 
                dp[1][i] += dp[0][i - 1];
            if(s[i - 1] == '1' || s[i - 1] == '?') 
                dp[0][i] += dp[1][i - 1];
            
            if(e[i - 1] == '0' || e[i - 1] == '?') 
                dp[0][i] += dp[0][i - 1];
            if(e[i - 1] == '1' || e[i - 1] == '?') 
                dp[1][i] += dp[1][i - 1];
            
            dp[0][i] %= MOD;
            dp[1][i] %= MOD;
        }
        
        int res = (dp[0][n] + dp[1][n]) % MOD;
        cout << res << endl;
    }
    
    return 0;
}