#include <iostream>
#include <string>

int main() {
    std::string num1, num2;
    std::cin >> num1 >> num2;

    std::string result;
    for (int i = 0; i < num1.length(); i++) {
        if (num1[i] == num2[i]) {
            result += '0';
        } else {
            result += '1';
        }
    }

    std::cout << result << std::endl;

    return 0;
}