#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    vector<int> open(n+1, 0);
    vector<int> close(n+1, 0);
    
    int cur = 0;
    for(int i = 0; i < m; i++) {
        if(s[i] == '(') cur++;
        else cur--;
    }
    
    open[0] = cur;
    close[0] = (cur > 0) ? 0 : -cur;
    
    for(int i = m; i < n; i++) {
        if(s[i-m] == '(') cur--;
        else cur++;
        
        if(s[i] == '(') cur++;
        else cur--;
        
        open[i-m+1] = cur;
        close[i-m+1] = (cur > 0) ? 0 : -cur;
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j > 0) dp[i][j] = dp[i-1][j-1];
            if(j < i) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= n-m; i++) {
        if(open[i] >= close[i]) {
            ans = (ans + dp[open[i]+close[i]][close[i]]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}