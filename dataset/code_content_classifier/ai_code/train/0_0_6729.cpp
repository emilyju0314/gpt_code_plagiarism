#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    if (S == "ABC") {
        std::cout << "ARC" << std::endl;
    } else if (S == "ARC") {
        std::cout << "ABC" << std::endl;
    }

    return 0;
}