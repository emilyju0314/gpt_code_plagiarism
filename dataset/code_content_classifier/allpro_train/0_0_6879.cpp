#include <iostream>
#include <string>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string colors;
    std::cin >> colors;

    bool *dp = new bool[n];
    dp[0] = true;

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = colors[i] == colors[i - 1];
        if (i >= 2 * k) {
            dp[i] |= dp[i - 2 * k];
        }

        if (dp[i]) {
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            std::cout << " ";
        }
        std::cout << (dp[i] ? "1" : "0");
    }
    std::cout << std::endl;

    delete[] dp;

    return 0;
}