#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    if ((A >= 1 && A <= 9) && (B >= 1 && B <= 9)) {
        std::cout << A * B << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}