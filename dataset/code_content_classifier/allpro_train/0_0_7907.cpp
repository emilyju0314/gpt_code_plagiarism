#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int countTransformations(string start, string end, int k) {
    int n = start.length();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    
    if(start == end) {
        return 1;
    }
    
    dp[0][0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        dp[i][0][0] = dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][0][0];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j-1][0]) % MOD;
            dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j-1][1]) % MOD;
        }
    }
    
    return dp[n][k][1];
}

int main() {
    string start, end;
    int k;
    
    cin >> start >> end >> k;
    
    int result = countTransformations(start, end, k);
    
    cout << result << endl;
    
    return 0;
}