#include <iostream>
#include <algorithm>

int main() {
    int n1, n2, n3, n4;
    std::cin >> n1 >> n2 >> n3 >> n4;

    // Put the inputs in an array
    int nums[4] = {n1, n2, n3, n4};

    // Sort the array to easily check if it can be arranged into "1974"
    std::sort(nums, nums+4);

    // Check if the sorted array corresponds to "1974"
    if (nums[0] == 1 && nums[1] == 4 && nums[2] == 7 && nums[3] == 9) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}