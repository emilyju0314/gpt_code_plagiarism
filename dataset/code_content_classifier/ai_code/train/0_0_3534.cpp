#include <iostream>
#include <iomanip>

int main() {
    double R1, R2, R3;

    std::cin >> R1 >> R2;

    R3 = 1 / (1/R1 + 1/R2);

    std::cout << std::fixed << std::setprecision(10) << R3 << std::endl;

    return 0;
}