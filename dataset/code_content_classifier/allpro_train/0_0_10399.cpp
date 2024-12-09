#include <iostream>

int main() {
    int x;
    std::cin >> x;

    bool found = false;
    for (int a = 1; a <= x; a++) {
        for (int b = 1; b <= a; b++) {
            if (a % b == 0 && a * b > x && a / b < x) {
                std::cout << a << " " << b << std::endl;
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        std::cout << "-1" << std::endl;
    }

    return 0;
}