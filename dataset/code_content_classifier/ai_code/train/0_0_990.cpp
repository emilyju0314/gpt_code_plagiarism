#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seats[i];
    }

    std::vector<long long> dp(n + 1, 1);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (seats[i - 1] == 0) {
            dp[i] = (dp[i - 1] * 2) % MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    std::cout << dp[n - 1] << std::endl;

    return 0;
}