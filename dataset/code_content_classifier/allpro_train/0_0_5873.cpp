#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> flips(N);
    for (int i = 0; i < N; i++) {
        std::cin >> flips[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(4, 9999));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 3; j++) {
            int nextFlips = std::min(j, flips[i]);
            if (dp[i][j] + nextFlips < dp[i + 1][nextFlips]) {
                dp[i + 1][nextFlips] = dp[i][j] + nextFlips;
            }
            int remainingFlips = flips[i] - nextFlips;
            if (remainingFlips > 0 && dp[i][j] + remainingFlips + 2 < dp[i + 1][2]) {
                dp[i + 1][2] = dp[i][j] + remainingFlips + 2;
            }
        }
    }

    int result = *min_element(dp[N].begin(), dp[N].end());
    std::cout << result << std::endl;

    return 0;
}