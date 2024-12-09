#include <iostream>
#include <vector>

int main() {
    int n, k;
    while (std::cin >> n >> k && n != 0 && k != 0) {
        std::vector<int> sequence(n);
        for (int i = 0; i < n; i++) {
            std::cin >> sequence[i];
        }

        int maxSum = 0;
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += sequence[i];
        }
        maxSum = currentSum;

        for (int i = k; i < n; i++) {
            currentSum = currentSum + sequence[i] - sequence[i - k];
            maxSum = std::max(maxSum, currentSum);
        }

        std::cout << maxSum << std::endl;
    }

    return 0;
}