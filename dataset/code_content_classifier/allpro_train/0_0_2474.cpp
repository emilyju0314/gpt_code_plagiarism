#include <iostream>
#include <string>

int main() {
    int x;
    std::string type;
    std::cin >> x >> type;

    if (type == "of week") {
        if (x == 1 || x == 7) {
            std::cout << 52 << std::endl;
        } else {
            std::cout << 52 << std::endl;
        }
    } else if (type == "of month") {
        if (x == 31) {
            std::cout << 7 << std::endl;
        } else {
            std::cout << 12 << std::endl;
        }
    }

    return 0;
}