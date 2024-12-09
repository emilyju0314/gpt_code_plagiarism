#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int ans = 0;
    std::vector<int> dp(k + 1, 0);
    dp[0] = 1;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        for (int j = std::min(k, sum); j >= 0; j--) {
            dp[j] += dp[j ^ sum];
        }

        if (sum >= k) {
            ans += dp[sum ^ k];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}