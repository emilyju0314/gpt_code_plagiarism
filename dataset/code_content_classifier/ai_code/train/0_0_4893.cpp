#include <iostream>
#include <cmath>

int main() {
    int l3, l4, l5;
    std::cin >> l3 >> l4 >> l5;

    double volume_triangular = (1.0 / 3) * (sqrt(3) / 4) * l3 * l3 * (sqrt(6) / 3) * l3;
    double volume_quadrangular = (1.0 / 3) * l4 * l4 * l4 * sqrt(3);
    double volume_pentagonal = (1.0 / 3) * (1.0 / 4) * sqrt(5 * (5 + 2 * sqrt(5))) * l5 * l5 * (1.0 / 3) * sqrt(5 + 2 * sqrt(5)) * l5;
    
    double total_volume = volume_triangular + volume_quadrangular + volume_pentagonal;

    std::cout << total_volume << std::endl;

    return 0;
}