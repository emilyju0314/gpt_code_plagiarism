#include <iostream>
#include <cmath>

int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    int min_operations = ceil((double)N / std::max(H, W));
    std::cout << min_operations << std::endl;

    return 0;
}