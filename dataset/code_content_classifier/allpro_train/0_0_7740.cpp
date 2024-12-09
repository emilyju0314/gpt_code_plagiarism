#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    int ways = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (std::abs(heights[i] - heights[j]) <= d) {
                ways++;
            }
        }
    }

    std::cout << ways << std::endl;

    return 0;
}