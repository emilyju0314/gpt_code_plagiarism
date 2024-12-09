#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int min_divisible = 2;
    while (min_divisible % N != 0) {
        min_divisible += 2;
    }

    std::cout << min_divisible << std::endl;

    return 0;
}