#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s, t;
    cin >> s >> t;
    
    int m = t.length();
    
    int dp[205][205][205]; // dp[i][j][l] is the maximum number of occurrences of t in the first i characters of s using j replacements and t[l] is the last character used in the sequence
    
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l < m; l++) {
                if(i == 0 || j == 0) {
                    dp[i][j][l] = 0;
                } else {
                    dp[i][j][l] = dp[i-1][j][l] + (s[i-1] == t[l] ? dp[i-1][j][l ^ 1] : 0);
                    if(s[i-1] != t[l]) {
                        dp[i][j][l] = max(dp[i][j][l], dp[i-1][j-1][l ^ 1] + 1);
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int j = 0; j <= k; j++) {
        for(int l = 0; l < m; l++) {
            ans = max(ans, dp[n][j][l]);
        }
    }
    
    cout << ans << endl;

    return 0;
}