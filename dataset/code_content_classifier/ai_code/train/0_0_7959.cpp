#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int N, M, K, Q;
    std::cin >> N >> M >> K >> Q;

    std::vector<std::vector<int>> dp(N, std::vector<int>(M + 1, 0));
    for(int i = 0; i < N; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if((j + k) % N < j) {
                    continue;
                }

                if((k / K) % 2 == 0) {
                    dp[(j + k) % N][i] = (dp[(j + k) % N][i] + dp[j][i - 1]) % MOD;
                }
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        std::cout << dp[c][(b + 1)] << std::endl;
    }

    return 0;
}