#include <iostream>
#include <vector>
#include <unordered_set>

bool isPerfectSquare(long long num) {
    long long root = sqrt(num);
    return (root * root == num);
}

int minSegments(std::vector<int>& nums) {
    int segments = 0;
    std::unordered_set<int> seen;
    for (int num : nums) {
        bool newSegment = true;
        for (int s : seen) {
            if (isPerfectSquare((long long)num * s)) {
                newSegment = false;
                break;
            }
        }
        if (newSegment) {
            segments++;
            seen.clear();
        }
        seen.insert(num);
    }
    return segments;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            std::cin >> nums[j];
        }

        int result = minSegments(nums);
        std::cout << result << std::endl;
    }

    return 0;
}