#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    
    string S1, S2;
    cin >> S1 >> S2;
    
    vector<vector<long long>> dp(N+1, vector<long long>(3, 0));
    dp[0][0] = 1;
    
    for(int i = 0; i < N; i++) {
        if(S1[i] == S2[i]) {
            dp[i+1][0] = (dp[i][1] + dp[i][2]) % MOD;
            dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
            dp[i+1][2] = (dp[i][0] + dp[i][1]) % MOD;
        } else {
            dp[i+1][0] = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
            dp[i+1][1] = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
            dp[i+1][2] = (dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
        }
    }
    
    long long result = (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
    cout << result << endl;
    
    return 0;
}