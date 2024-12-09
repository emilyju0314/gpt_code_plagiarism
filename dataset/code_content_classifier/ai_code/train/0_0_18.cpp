#include <iostream>
#include <vector>

bool isDistinct(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] == v[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<int> rowSums(2), colSums(2), diaSums(2);
    
    for (int i = 0; i < 2; i++) {
        std::cin >> rowSums[i];
    }
    for (int i = 0; i < 2; i++) {
        std::cin >> colSums[i];
    }
    for (int i = 0; i < 2; i++) {
        std::cin >> diaSums[i];
    }
    
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (i != j) {
                std::vector<int> nums = {i, j, 0, 0};
                nums[2] = rowSums[0] - i;
                nums[3] = rowSums[1] - j;
                
                if (isDistinct(nums) && nums[0] + nums[2] == colSums[0] && nums[1] + nums[3] == colSums[1] && nums[0] + nums[3] == diaSums[0] && nums[1] + nums[2] == diaSums[1]) {
                    for (int k = 0; k < 2; k++) {
                        std::cout << nums[k] << " ";
                    }
                    std::cout << std::endl;
                    for (int k = 2; k < 4; k++) {
                        std::cout << nums[k] << " ";
                    }
                    std::cout << std::endl;
                    return 0;
                }
            }
        }
    }
    
    std::cout << "-1" << std::endl;
    
    return 0;
}