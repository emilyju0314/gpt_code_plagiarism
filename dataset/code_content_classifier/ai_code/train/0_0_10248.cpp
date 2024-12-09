#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (i != j && (nums[i] & nums[j]) == 0) {
                std::cout << nums[j] << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "-1 ";
        }
    }

    return 0;
}