#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    int N, R;
    std::cin >> N >> R;

    std::vector<int> F(N), S(N), P(N);

    for (int i = 0; i < N; i++) {
        std::cin >> F[i] >> S[i] >> P[i];
    }

    std::vector<double> dp(R + 1, 1e9);
    dp[0] = 0;

    for (int t = 1; t <= R; t++) {
        for (int i = 0; i < N; i++) {
            double x = 0.01 * P[i];
            double y = 1 - x;
            dp[t] = std::min(dp[t], (x * std::min(F[i], t) + y * dp[std::max(0, t - S[i])]) + 1);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << dp[R] << std::endl;

    return 0;
}