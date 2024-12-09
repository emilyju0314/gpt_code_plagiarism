#include <iostream>
#include <vector>
#include <cmath>

#define MOD 998244353

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }
    
    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(N * 400 + 1));
    dp[0][0] = 1;
    
    for(int i = 0; i < N; i++){
        std::vector<long long> dpsum(N * 400 + 1, 0);
        for(int j = 0; j <= N * 400; j++) {
            dpsum[j] = (dp[i][j] + (j ? dpsum[j - 1] : 0)) % MOD;
        }
        
        for(int j = 0; j <= N * 400; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (N - i) % MOD) % MOD;
            if(j + A[i] <= N * 400) {
                dp[i + 1][j + A[i]] = (dp[i + 1][j + A[i]] - dp[i][j] * (N - i) % MOD + MOD) % MOD;
            }
            if(j + A[i] * B[i] + B[i] <= N * 400) {
                dp[i + 1][j + A[i] * B[i] + B[i]] = (dp[i + 1][j + A[i] * B[i] + B[i]] + dp[i][j] * dpsum[j+A[i] * (B[i] - 1)] % MOD) % MOD;
            }
        }
    }
    
    long long ans = 0;
    for(int j = 1; j <= N * 400; j++){
        ans = (ans + dp[N][j] * j % MOD) % MOD;
    }
    
    std::cout << ans << "\n";
    
    return 0;
}