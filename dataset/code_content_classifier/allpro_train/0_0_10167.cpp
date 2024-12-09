#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    string a;
    cin >> a;
    
    int k;
    cin >> k;
    
    int n = a.size() * k;
    
    long long ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(2, 0));  // dp[i][j] stores the number of ways to form a number divisible by 5 using first i characters and j deletions
    
    for(int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] * 10 + (a[(i-1) % a.size()] - '0')) % 5;
        
        if(dp[i][0] == 0) {
            dp[i][1] = 1; // The number itself is divisible by 5, so there is one way to delete characters
        }
        
        if(i > a.size()) {
            dp[i][1] = (dp[i][1] + dp[i - a.size()][1]) % MOD; // Add the ways to delete characters before the current prefix
        }
        
        ans = (ans + dp[i][1]) % MOD; // Update the total number of ways
    }
    
    cout << ans << endl;
    
    return 0;
}