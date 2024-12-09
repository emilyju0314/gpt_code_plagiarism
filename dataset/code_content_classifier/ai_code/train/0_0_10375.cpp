#include <iostream>

int main() {
    int N, A, B;
    std::cin >> N >> A >> B;

    if ((B - A) % 2 == 0) {
        std::cout << "Borys" << std::endl;
    } else {
        std::cout << "Alice" << std::endl;
    }

    return 0;
}