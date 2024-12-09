#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    if (A == B) {
        std::cout << "Draw" << std::endl;
    } else if ((A == 1 && B != 1) || (A > B && B != 1)) {
        std::cout << "Alice" << std::endl;
    } else {
        std::cout << "Bob" << std::endl;
    }

    return 0;
}