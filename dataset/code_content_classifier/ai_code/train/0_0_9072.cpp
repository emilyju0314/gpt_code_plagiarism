#include <iostream>

int main() {
    int K;
    std::cin >> K;

    int even_count = K / 2;
    int odd_count = K - even_count;

    int total_ways = even_count * odd_count;
    std::cout << total_ways << std::endl;

    return 0;
}