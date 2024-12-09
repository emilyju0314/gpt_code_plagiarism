#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countSequences(int N, int M) {
    std::vector<std::vector<int>> dp(N+1, std::vector<int>(M+1, 0));
    dp[1][0] = 1;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (j == k) continue;
                if (k < j) {
                    dp[j][i] = (dp[j][i] + dp[k][i-1]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        result = (result + dp[i][M]) % MOD;
    }

    return result;
}

int main() {
    int N, M;
    std::cin >> N >> M;

    int result = countSequences(N, M);
    std::cout << result << std::endl;

    return 0;
}