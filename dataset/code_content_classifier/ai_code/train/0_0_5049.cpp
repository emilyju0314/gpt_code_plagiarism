#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, h;
    std::cin >> n >> h;

    std::vector<int> nums(n);
    std::vector<int> partition(n, 1);

    for(int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    int min_diff = nums[n-1] + nums[n-2] + h - nums[0] - nums[1];
    std::cout << min_diff << std::endl;

    for(int i = 0; i < n; i++) {
        if(i < 2) {
            partition[i] = 2;
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << partition[i] << " ";
    }

    return 0;
}