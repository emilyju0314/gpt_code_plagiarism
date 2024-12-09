#include <iostream>
#include <vector>
#include <cmath>

int binarySearch(std::vector<int>& nums, int target) {
    int comparisons = 0;
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;

        if(nums[mid] == target) {
            return comparisons;
        } else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return comparisons;
}

int main() {
    int n;
    while(std::cin >> n && n != 0) {
        std::vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            std::cin >> nums[i];
        }

        int target;
        std::cin >> target;

        int comparisons = binarySearch(nums, target);
        std::cout << comparisons << std::endl;
    }
    
    return 0;
}