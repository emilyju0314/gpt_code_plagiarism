#include <iostream>
#include <cmath>

int main() {
    double A, B;
    std::cin >> A >> B;

    double volume = (M_PI * A * A * B) / 2;

    std::cout << volume << std::endl;

    return 0;
}