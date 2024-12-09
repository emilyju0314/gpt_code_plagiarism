#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(n);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        dp[i] = std::max(dp[i-1] + std::abs(a[i] - a[i-1]), std::abs(a[i] - 1));
    }

    int operations = 0;
    for(int i = 0; i < n; i++) {
        operations += dp[i];
    }

    std::cout << operations << std::endl;

    return 0;
}