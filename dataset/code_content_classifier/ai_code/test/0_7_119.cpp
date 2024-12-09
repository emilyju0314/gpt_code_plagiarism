#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> heights(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> heights[i];
            sum += heights[i];
        }

        int avg = sum / n;
        int result = 0;

        for (int i = 0; i < n; i++) {
            result += std::max(0, heights[i] - avg);
        }

        std::cout << result << std::endl;
    }

    return 0;
}