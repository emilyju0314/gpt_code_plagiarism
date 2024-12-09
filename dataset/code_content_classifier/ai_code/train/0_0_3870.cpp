#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    int m = 0;
    std::vector<int> descensions;

    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > 0 && nums[i + 1] > 0) {
            int cost = std::min(nums[i], nums[i + 1]);
            nums[i] -= cost;
            nums[i + 1] -= cost;
            descensions.push_back(i + 1);
            m++;
        }
    }

    std::cout << m << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << descensions[i] << std::endl;
    }

    return 0;
}