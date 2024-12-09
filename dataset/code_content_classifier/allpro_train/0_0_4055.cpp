#include <iostream>
#include <vector>

bool checkArrangement(std::vector<int> nums) {
    int leftMax = 0, rightMax = 0;
    
    for(int num : nums) {
        if(num > leftMax && num > rightMax) {
            return false;
        } else if(num > leftMax) {
            rightMax = num;
        } else {
            leftMax = num;
        }
    }
    
    return true;
}

int main() {
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::vector<int> nums(10);
        for(int j = 0; j < 10; j++) {
            std::cin >> nums[j];
        }
        
        if(checkArrangement(nums)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}