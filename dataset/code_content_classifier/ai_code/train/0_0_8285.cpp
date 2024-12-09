#include <iostream>
#include <string>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    std::string decimal;
    int remainder = a % b;
    int position = 1;
    bool found = false;

    while (remainder != 0 && !found) {
        remainder *= 10;
        decimal += std::to_string(remainder / b);
        remainder %= b;

        for (char digit : decimal) {
            if (digit - '0' == c) {
                found = true;
                break;
            }
            position++;
        }
    }

    if (found) {
        std::cout << position;
    } else {
        std::cout << -1;
    }

    return 0;
}