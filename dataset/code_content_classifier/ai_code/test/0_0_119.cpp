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

        int max_height = *std::max_element(heights.begin(), heights.end());
        int min_height = *std::min_element(heights.begin(), heights.end());

        int min_ugliness = std::max(0, (sum - n*min_height) % n);

        std::cout << min_ugliness << std::endl;
    }

    return 0;
}