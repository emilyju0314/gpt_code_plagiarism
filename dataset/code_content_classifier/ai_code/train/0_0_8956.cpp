#include <iostream>
#include <string>
#include <cmath>

double golden_to_decimal(const std::string& golden) {
    double result = 0.0;
    double a = 1.0; // Starting with the first Fibonacci number
    double b = 1.0; // Second Fibonacci number

    for (int i = golden.length() - 1; i >= 0; --i) {
        if (golden[i] == '1') {
            result += a;
        }

        double temp = b;
        b += a;
        a = temp;
    }

    return result;
}

int main() {
    std::string number1, number2;
    std::cin >> number1 >> number2;

    double decimal1 = golden_to_decimal(number1);
    double decimal2 = golden_to_decimal(number2);

    if (std::abs(decimal1 - decimal2) < 1e-9) {
        std::cout << "=";
    } else if (decimal1 < decimal2) {
        std::cout << "<";
    } else {
        std::cout << ">";
    }

    return 0;
}