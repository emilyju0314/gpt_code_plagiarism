#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 998244353;

int main() {
    string S;
    cin >> S;
    
    int N = S.length();
    
    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(2*N+1, vector<int>(3*N+1, 0)));
    dp[0][0][0] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 2*N; j++) {
            for (int k = 0; k <= 3*N; k++) {
                dp[i+1][j+1][k+1] = (dp[i+1][j+1][k+1] + dp[i][j][k]) % MOD;
                if (S[i] == '0' || S[i] == '1') {
                    if (j > 0) dp[i+1][j-1][k+1] = (dp[i+1][j-1][k+1] + dp[i][j][k]) % MOD;
                }
                if (S[i] == '2' || S[i] == '1') {
                    if (k > 0) dp[i+1][j][k-1] = (dp[i+1][j][k-1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    
    long long ans = 0;
    for (int j = 0; j <= 2*N; j++) {
        for (int k = 0; k <= 3*N; k++) {
            ans = (ans + dp[N][j][k]) % MOD;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}