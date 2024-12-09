#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<long long> dp(100001, 0);
    for(int i = 0; i < n; i++) {
        dp[nums[i]]++;
    }

    for(int i = 2; i < 100001; i++) {
        dp[i] = std::max(dp[i - 1], dp[i] + 1LL * i * dp[i - 2]);
    }

    std::cout << dp[100000] << std::endl;

    return 0;
}