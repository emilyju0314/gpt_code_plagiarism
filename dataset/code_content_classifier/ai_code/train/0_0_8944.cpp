#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1000000007;

int dp[1001][1001]; // DP table to store the number of ways to transform start into end
string start, end;
int k;

int countWays(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if (k == 0) {
        dp[i][j] = (start.substr(0, i) == end.substr(j-i, i));
    } else {
        dp[i][j] = (countWays(i, j) + countWays(i-1, j)) % MOD;
    }
    
    return dp[i][j];
}

int main() {
    cin >> start >> end >> k;
    
    memset(dp, -1, sizeof(dp));
    
    int n = start.size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + countWays(i, n)) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}