#include <iostream>
#include <cmath>

int main() {
    long long m;
    std::cin >> m;

    long long remaining_volume = m;
    long long total_volume = 0;
    long long num_blocks = 0;

    for (long long side = floor(pow(remaining_volume, 1.0/3.0)); side >= 1; side--) {
        long long block_volume = side * side * side;

        while (remaining_volume >= block_volume) {
            num_blocks++;
            total_volume += block_volume;
            remaining_volume -= block_volume;
        }
    }

    std::cout << num_blocks << " " << total_volume << std::endl;

    return 0;
}