#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, min, max;
    std::cin >> n >> m >> min >> max;

    std::vector<int> temperatures(m);
    for (int i = 0; i < m; i++) {
        std::cin >> temperatures[i];
    }

    int current_min = *std::min_element(temperatures.begin(), temperatures.end());
    int current_max = *std::max_element(temperatures.begin(), temperatures.end());

    if (current_min < min || current_max > max) {
        std::cout << "Incorrect" << std::endl;
    } else {
        std::cout << "Correct" << std::endl;
    }

    return 0;
}