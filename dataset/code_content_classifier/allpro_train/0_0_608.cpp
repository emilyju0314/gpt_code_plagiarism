#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int total = n * n;
    std::vector<int> nums(total);

    for (int i = 0; i < total; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));

    int idx = 0;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if(nums[idx] == nums[idx+1] && nums[idx] == nums[total-idx-1] && nums[total-idx-1] == nums[total-idx-2]) {
                matrix[i][j] = matrix[n-1-i][j] = matrix[i][n-1-j] = matrix[n-1-i][n-1-j] = nums[idx];
                idx += 2;
            } else {
                std::cout << "NO";
                return 0;
            }
        }
    }

    if(n % 2 == 1) {
        int center_value = nums[idx];

        for (int i = 0; i < n / 2; i++) {
            if(nums[idx] == nums[idx+1] && nums[idx] == nums[total-idx-1]) {
                matrix[i][n/2] = matrix[n-1-i][n/2] = nums[idx];
                idx += 2;
            } else {
                std::cout << "NO";
                return 0;
            }
        }

        for (int j = 0; j < n / 2; j++) {
            if(nums[idx] == nums[idx+1] && nums[idx] == nums[total-idx-1]) {
                matrix[n/2][j] = matrix[n/2][n-1-j] = nums[idx];
                idx += 2;
            } else {
                std::cout << "NO";
                return 0;
            }
        }
        matrix[n/2][n/2] = center_value;
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}