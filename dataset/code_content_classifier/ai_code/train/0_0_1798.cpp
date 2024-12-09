#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    int times = 0;
    if (B / A <= C) {
        times = B / A;
    } else {
        times = C;
    }

    std::cout << times << std::endl;

    return 0;
}