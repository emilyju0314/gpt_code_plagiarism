#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool canBuild(string s, string t) {
    int m = s.length();
    int n = t.length();
    
    bool dp[m+1][n+1];
    memset(dp, false, sizeof(dp));
    
    dp[0][0] = true;
    
    for(int i=1; i<=m; i++) {
        dp[i][0] = true;
    }
    
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = dp[i][j] || dp[i-1][j];
        }
    }
    
    return dp[m][n];
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        string s, t;
        cin >> s >> t;
        
        if(canBuild(s, t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}