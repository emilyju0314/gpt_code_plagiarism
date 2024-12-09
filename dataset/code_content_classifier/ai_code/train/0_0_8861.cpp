#include <iostream>
#include <iomanip>

int main() {
    int xi;
    int FOO = 0;
    int BAR = 0;
    int BAZ = 0;
    int QUZ = 1;

    while(std::cin >> xi) {
        int PUR = xi;
        FOO += PUR;
        BAR += 1;

        if (std::max(FOO * QUZ, BAR * BAZ) == FOO * QUZ) {
            BAZ = FOO;
            QUZ = BAR;
        }

    }

    double result = static_cast<double>(BAZ) / QUZ;
    std::cout << std::fixed << std::setprecision(6) << result << std::endl;

    return 0;
}