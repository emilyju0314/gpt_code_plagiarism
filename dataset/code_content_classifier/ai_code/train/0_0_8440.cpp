#include <iostream>

int main() {
    int n;
    std::cin >> n;

    if(n % 2 == 0) {
        std::cout << "white" << std::endl;
        std::cout << "1 2" << std::endl;
    } else {
        std::cout << "black" << std::endl;
    }

    return 0;
}