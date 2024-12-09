#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    bool possible = true;

    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && nums[i] % 2 == 0) {
            possible = false;
            break;
        }
    }

    if (n % 2 == 0 || nums[0] % 2 == 0 || nums[n-1] % 2 == 0) {
        possible = false;
    }

    if (possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}