#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    int maxBuns = 0;
    int lowestStudentHeight = *std::min_element(heights.begin(), heights.end());
    int step = 0;

    for(int i = 0; i < n; i++) {
        int bunsNeeded = 0;
        if(heights[i] > lowestStudentHeight) {
            int diff = heights[i] - lowestStudentHeight;
            if(diff % 2 == 0) {
                bunsNeeded = diff / 2;
            } else {
                bunsNeeded = diff / 2 + 1;
            }
            step = std::max(step, diff);
        }
        maxBuns = std::max(maxBuns, bunsNeeded);
    }

    std::cout << maxBuns << std::endl;
    std::cout << lowestStudentHeight << " " << step << std::endl;

    return 0;
}