#include <iostream>
#include <string>
#include <cmath>

std::string convertToBinary(double num) {
    int intPart = static_cast<int>(num);
    double decPart = num - intPart;

    // Convert integer part to binary
    std::string intBinary = "";
    while (intPart > 0) {
        intBinary = std::to_string(intPart % 2) + intBinary;
        intPart /= 2;
    }

    // Convert decimal part to binary
    std::string decBinary = "";
    for (int i = 0; i < 4; i++) {
        decPart *= 2;
        if (decPart >= 1) {
            decBinary += "1";
            decPart -= 1;
        } else {
            decBinary += "0";
        }
    }

    // Check if the binary representation fits within the limit
    if (intBinary.length() <= 8 && decBinary.length() <= 4) {
        return intBinary + "." + decBinary;
    } else {
        return "NA";
    }
}

int main() {
    double num;
    while (true) {
        std::cin >> num;
        if (num < 0) {
            break;
        }
        std::cout << convertToBinary(num) << std::endl;
    }
    return 0;
}