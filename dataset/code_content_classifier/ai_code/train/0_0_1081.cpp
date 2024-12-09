#include <iostream>
#include <vector>

int main() {
    int sum, limit;
    std::cin >> sum >> limit;

    std::vector<int> set;
    int currentSum = sum;
    int currentLimit = limit;

    while (currentSum > 0) {
        int lowbit = 1;
        while (lowbit * 2 <= currentLimit && (lowbit * 2) <= currentSum) {
            lowbit *= 2;
        }

        if (lowbit == 1 && currentSum < currentLimit) {
            currentLimit = currentSum;
        }

        set.push_back(lowbit);
        currentSum -= lowbit;
        currentLimit--;
    }
    
    if (currentSum == 0) {
        std::cout << set.size() << std::endl;
        for (int num : set) {
            std::cout << num << " ";
        }
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}