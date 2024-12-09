#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> heights(10);

    for(int i = 0; i < 10; i++) {
        std::cin >> heights[i];
    }

    std::sort(heights.begin(), heights.end(), std::greater<int>());

    std::cout << heights[0] << std::endl;
    std::cout << heights[1] << std::endl;
    std::cout << heights[2] << std::endl;

    return 0;
}