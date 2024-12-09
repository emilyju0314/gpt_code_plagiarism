#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, R;
    std::cin >> N >> R;

    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    bool canSort = true;
    for (int i = 0; i < R; i++) {
        if (nums[i] != i + 1) {
            canSort = false;
            break;
        }
    }

    if (canSort) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}