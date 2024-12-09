#include <iostream>

int main() {
    int T1, T2, R1, R2;
    std::cin >> T1 >> T2 >> R1 >> R2;

    if (R1 == -1 && R2 == -1) {
        if (T1 < T2) {
            std::cout << "Alice" << std::endl;
        } else if (T1 > T2) {
            std::cout << "Bob" << std::endl;
        } else {
            std::cout << "Draw" << std::endl;
        }
    } else if (R1 == -1) {
        std::cout << "Bob" << std::endl;
    } else if (R2 == -1) {
        std::cout << "Alice" << std::endl;
    } else {
        if (R1 > R2) {
            std::cout << "Alice" << std::endl;
        } else if (R1 < R2) {
            std::cout << "Bob" << std::endl;
        } else {
            if (T1 < T2) {
                std::cout << "Alice" << std::endl;
            } else if (T1 > T2) {
                std::cout << "Bob" << std::endl;
            } else {
                std::cout << "Draw" << std::endl;
            }
        }
    }

    return 0;
}