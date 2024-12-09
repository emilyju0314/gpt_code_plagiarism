#include <iostream>
#include <iomanip>

int main() {
    int p1, q1, p2, q2;
    std::cin >> p1 >> q1 >> p2 >> q2;

    // Probability that SmallR wins when SmallR starts
    double dp[101][101] = {0};
    for (int i = 0; i <= 100; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = (p1 * q2 * dp[i-1][j] + p1 * p2 * dp[i-1][j-1]) / (q1 * q2 + p1 * q2);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << dp[100][100] << std::endl;

    return 0;
}