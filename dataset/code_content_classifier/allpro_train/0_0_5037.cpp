#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            std::cout << "1";
        } else {
            std::cout << nums[i - 1];
        }
        
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    
    return 0;
}