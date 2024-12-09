#include <iostream>
#include <vector>
#include <algorithm>

int count = 0;

bool isValid(std::vector<int> &nums) {
    if (nums[0] + nums[1] == nums[2] &&
        nums[3] - nums[2] == nums[4] &&
        nums[5] * nums[6] == nums[7] &&
        nums[8] / nums[6] == nums[7]) {
        return true;
    }
    return false;
}

void solve(std::vector<int> &nums, int idx) {
    if (idx == 9) {
        if (isValid(nums)) {
            count++;
        }
        return;
    }

    if (nums[idx] != -1) {
        solve(nums, idx + 1);
    } else {
        std::vector<bool> used(10, false);
        for (int i = 0; i < 9; i++) {
            if (nums[i] != -1) {
                used[nums[i]] = true;
            }
        }

        for (int i = 1; i <= 9; i++) {
            if (!used[i]) {
                nums[idx] = i;
                solve(nums, idx + 1);
                nums[idx] = -1;
            }
        }
    }
}

int main() {
    std::vector<int> nums(9);
    for (int i = 0; i < 9; i++) {
        std::cin >> nums[i];
    }

    solve(nums, 0);
    std::cout << count << std::endl;

    return 0;
}