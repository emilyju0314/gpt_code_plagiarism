#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int negativeCount = 0, zeroCount = 0, cost = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            cost += std::abs(nums[i] + 1);
            negativeCount++;
        } else if (nums[i] > 0) {
            cost += std::abs(nums[i] - 1);
        } else {
            zeroCount++;
            cost++;
        }
    }

    // If there are odd number of negative numbers and at least one zero,
    // it is possible to make the product equal to 1.
    if (negativeCount % 2 == 1 && zeroCount == 0) {
        cost += 2;
    }

    std::cout << cost << std::endl;

    return 0;
}