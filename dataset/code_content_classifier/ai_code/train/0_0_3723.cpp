#include <iostream>
#include <cmath>

int main() {
    int num1, num2, num3, num4;
    double result;

    // Input
    std::cin >> num1 >> num2 >> num3 >> num4;

    // Calculation
    result = (pow((num1 + num2), 2)) / (num3 + num4);

    // Output
    std::cout << result;

    return 0;
}