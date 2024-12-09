#include <iostream>
#include <vector>
#include <algorithm>

int longestArithmeticProgression(std::vector<int>& nums) {
    int n = nums.size();
    int result = 2; // initialize result with the minimum possible length of an arithmetic progression

    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 2)); // initializing DP table to store length of arithmetic progression ending at i, j

    // populate the DP table
    for (int j = n-2; j > 0; j--) {
        int i = j - 1;
        int k = j + 1;

        while (i >= 0 && k < n) {
            if (nums[i] + nums[k] < 2 * nums[j]) {
                k++;
            } else if (nums[i] + nums[k] > 2 * nums[j]) {
                i--;
            } else {
                dp[i][j] = dp[j][k] + 1;
                result = std::max(result, dp[i][j]);

                i--;
                k++;
            }
        }
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int result = longestArithmeticProgression(nums);

    std::cout << result << std::endl;

    return 0;
}