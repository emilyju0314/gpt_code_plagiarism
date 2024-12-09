#include <iostream>
#include <string>

int main() {
    std::string n;
    std::cin >> n;

    if (n.size() <= 3) {
        std::cout << "byte" << std::endl;
    } else if (n.size() <= 5) {
        std::cout << "short" << std::endl;
    } else if (n.size() <= 10) {
        std::cout << "int" << std::endl;
    } else if (n.size() <= 19) {
        std::cout << "long" << std::endl;
    } else {
        std::cout << "BigInteger" << std::endl;
    }

    return 0;
}