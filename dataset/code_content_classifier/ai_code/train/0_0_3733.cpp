#include <iostream>
#include <vector>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;

    long long sum = 0;
    std::vector<int> nums;

    for (int i = n; i >= 1; i--) {
        int num = 1;
        while ((num * num * (n - i + 1) < x - sum) && (num < y)) {
            num++;
        }
        
        if (num <= y) {
            nums.push_back(num);
            sum += num * num;
        } else {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    for (int num : nums) {
        std::cout << num << std::endl;
    }

    return 0;
}