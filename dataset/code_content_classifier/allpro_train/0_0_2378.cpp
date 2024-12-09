#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int sum = 0;
    for (int i = 1; i < n; i++) {
        while (nums[i] >= nums[i - 1]) {
            nums[i] -= nums[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    std::cout << sum << std::endl;

    return 0;
}