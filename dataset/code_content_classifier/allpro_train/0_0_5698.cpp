#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<long long>> dp(M+1, vector<long long>(N+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = (dp[i-1][j] * (N-j) % MOD);
            if(j > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * j % MOD) % MOD;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i <= N; i++) {
        ans = (ans + dp[M][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}