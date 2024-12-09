#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;

    int sum = A + B;
    if(sum >= 10) {
        std::cout << "error" << std::endl;
    } else {
        std::cout << sum << std::endl;
    }

    return 0;
}