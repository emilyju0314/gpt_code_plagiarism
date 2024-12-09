#include <iostream>
#include <algorithm>

int main() {
    int d1, d2, d3;
    std::cin >> d1 >> d2 >> d3;

    int min_distance = std::min({d1 + d2 + d3, d1 + d1 + d2 + d2});
    min_distance = std::min(min_distance, d1 + d3 + d3 + d1);
    min_distance = std::min(min_distance, d2 + d3 + d3 + d2);

    std::cout << min_distance << std::endl;

    return 0;
}