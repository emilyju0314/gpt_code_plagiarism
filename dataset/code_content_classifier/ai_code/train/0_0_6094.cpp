#include <iostream>
#include <string>
#include <vector>

int main() {
    int a;
    std::cin >> a;

    std::string expression;
    std::cin >> expression;

    int result = 0;
    bool incrementFirst = false;

    for (size_t i = 0; i < expression.size();) {
        int coefficient = 1;

        if (expression[i] >= '0' && expression[i] <= '9') {
            coefficient = expression[i] - '0';
            i++;
        }

        if (expression[i] == 'a') {
            if (expression[i+1] == '+') {
                incrementFirst = true;
                i += 2;
            } else {
                incrementFirst = false;
                i++;
            }

            if (incrementFirst) {
                result += coefficient * (a + 1);
                a++;
            } else {
                result += coefficient * a;
                a++;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}