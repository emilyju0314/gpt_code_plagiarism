#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string T;
    std::cin >> T;

    int sum = 0;
    int num_zeros = std::count(T.begin(), T.end(), '0');
    int num_ones = T.size() - num_zeros;

    sum = std::min(num_zeros, num_ones) * 2;

    std::cout << sum << std::endl;

    return 0;
}