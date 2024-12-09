#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x;
    std::cin >> x;

    int first_num = std::ceil(x);
    int second_num = 1 + std::ceil(10 * (x - std::floor(x)));

    std::cout << first_num << " " << second_num << std::endl;

    return 0;
}