#include <iostream>
#include <string>
#include <algorithm>

std::string multiplyBigNumbers(std::string num1, std::string num2) {
    int sign = 1;
    if (num1[0] == '-') {
        sign *= -1;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        sign *= -1;
        num2 = num2.substr(1);
    }

    int size1 = num1.size();
    int size2 = num2.size();
    std::string result(size1 + size2, '0');

    for (int i = size1 - 1; i >= 0; i--) {
        for (int j = size2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
            result[i + j] += mul / 10;
            result[i + j + 1] = (mul % 10) + '0';
        }
    }

    // Clearing leading zeros
    int index = result.find_first_not_of('0');
    if (index != -1) {
        result = result.substr(index);
    } else {
        return "0";
    }

    if (sign == -1) {
        result = "-" + result;
    }
    return result;
}

int main() {
    std::string num1, num2;
    std::cin >> num1 >> num2;

    std::cout << multiplyBigNumbers(num1, num2) << std::endl;

    return 0;
}