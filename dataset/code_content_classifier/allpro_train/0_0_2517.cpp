#include <iostream>
#include <cmath>

int main() {
    int a, b, angleC;
    std::cin >> a >> b >> angleC;

    double angleRad = angleC * M_PI / 180.0; // Convert angle to radians

    // Calculate area
    double S = 0.5 * a * b * sin(angleRad);

    // Calculate circumference
    double L = a + b + sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(angleRad));

    // Calculate height
    double h = b * sin(angleRad);

    std::cout << std::fixed;
    std::cout.precision(8);
    std::cout << S << std::endl;
    std::cout << L << std::endl;
    std::cout << h << std::endl;

    return 0;
}