#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (permutation[j] > permutation[i]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_independent_set = *std::max_element(dp.begin(), dp.end());
    std::cout << max_independent_set << std::endl;

    return 0;
}