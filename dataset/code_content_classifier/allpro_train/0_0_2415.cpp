#include <iostream>

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

int main() {
    int a, b;
    bool first = true;

    while (std::cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        
        if (!first) {
            std::cout << std::endl;
        } else {
            first = false;
        }

        bool hasLeapYear = false;
        for (int i = a; i <= b; i++) {
            if (isLeapYear(i)) {
                std::cout << i << std::endl;
                hasLeapYear = true;
            }
        }

        if (!hasLeapYear) {
            std::cout << "NA" << std::endl;
        }
    }

    return 0;
}