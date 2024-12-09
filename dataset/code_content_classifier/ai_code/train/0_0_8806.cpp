#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 998244353

using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;
    
    int n = S.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1)); // dp[i][j] represents the number of ways to rearrange the first i characters of S with j operations
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }
    
    vector<int> pref(n+1); // pref[i] represents the number of ways to rearrange the first i characters of S without performing any operation
    pref[0] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = (pref[i-1] + dp[i][0]) % MOD;
    }
    
    int result = 0;
    for (int i = 0; i <= K; i++) {
        int curr = (dp[n][i] * pref[n-1]) % MOD;
        result = (result + curr) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}