#include <iostream>
#include <cmath>

int main() {
    int m, R;
    std::cin >> m >> R;

    double total_distance = 0;
    double sqrt_2 = std::sqrt(2);

    for (int i = 0; i < m; i++) {
        total_distance += sqrt_2 * R * 2;
    }

    total_distance += R * 2;

    std::cout << total_distance << std::endl;

    return 0;
} 

This code calculates the total distance the fly went along the coordinate plane during the experiment and outputs the average distance.