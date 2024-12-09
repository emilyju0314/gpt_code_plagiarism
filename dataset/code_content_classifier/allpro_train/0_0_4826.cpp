#include <iostream>
#include <cmath>

int main() {
    int A, B;
    std::cin >> A >> B;

    if ((A + B) % 2 != 0) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        int K = (A + B) / 2;
        std::cout << K << std::endl;
    }

    return 0;
}