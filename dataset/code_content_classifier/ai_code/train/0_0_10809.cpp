#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> C(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> C[i][j];
        }
    }
    
    vector<vector<long long>> dp(N+1, vector<long long>(N+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = dp[i-1][j];
            for(int k = 0; k < N; k++) {
                if(C[i-1][k] == 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                }
            }
        }
    }
    
    long long ans = 0;
    for(int j = 0; j <= N; j++) {
        ans = (ans + dp[N][j]) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}