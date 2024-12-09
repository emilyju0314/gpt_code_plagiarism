#include <iostream>
#include <string>

int main() {
    std::string expression;
    std::cin >> expression;

    int result = expression[0] - '0';

    for (int i = 1; i < expression.length(); i += 2) {
        char operation = expression[i];
        int operand = expression[i + 1] - '0';

        if (operation == '+') {
            result -= operand;
        }
        else if (operation == '-') {
            result += operand;
        }
    }

    std::cout << result << std::endl;

    return 0;
}