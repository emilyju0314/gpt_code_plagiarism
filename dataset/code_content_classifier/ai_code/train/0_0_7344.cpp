#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<double> heights;
    double height;

    // Read mountain heights
    while(std::cin >> height) {
        heights.push_back(height);
    }

    // Find the highest and lowest mountains
    double highest = *std::max_element(heights.begin(), heights.end());
    double lowest = *std::min_element(heights.begin(), heights.end());

    // Output the elevation difference
    std::cout << std::fixed << std::setprecision(2) << highest - lowest << std::endl;

    return 0;
}