#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Calculate the sum of all integers from 1 to n
    int totalSum = (n * (n + 1)) / 2;

    // Calculate the target sum for each group
    int targetSum = totalSum / 2;

    // Initialize vector to store integers in first group
    std::vector<int> firstGroup;

    // Iterate through integers from n down to 1
    for (int i = n; i >= 1; i--) {
        if (targetSum - i >= 0) {
            targetSum -= i;
            firstGroup.push_back(i);
        }
    }

    // Calculate the absolute difference between the sums of two groups
    int absoluteDifference = totalSum - 2 * targetSum;

    // Output the result
    std::cout << absoluteDifference << std::endl;
    std::cout << firstGroup.size() << " ";
    for (int num : firstGroup) {
        std::cout << num << " ";
    }
    
    return 0;
}