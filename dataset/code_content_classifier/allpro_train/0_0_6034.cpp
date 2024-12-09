#include <iostream>
#include <cctype>

int main() {
    char alpha;
    std::cin >> alpha;

    if (isupper(alpha)) {
        std::cout << "A" << std::endl;
    } else {
        std::cout << "a" << std::endl;
    }

    return 0;
}