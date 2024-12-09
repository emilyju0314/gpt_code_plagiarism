#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int L;
    std::cin >> L;

    double a = L / 3.0;
    double volume = a * a * a;

    std::cout << std::fixed << std::setprecision(9) << volume << std::endl;

    return 0;
}