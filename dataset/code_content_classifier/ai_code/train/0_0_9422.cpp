#include <iostream>

int main() {
    int N;
    std::cin >> N;

    if(N <= 999) {
        std::cout << "ABC" << std::endl;
    } else {
        std::cout << "ABD" << std::endl;
    }

    return 0;
}