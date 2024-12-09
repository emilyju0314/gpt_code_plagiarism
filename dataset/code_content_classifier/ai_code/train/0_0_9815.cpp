#include <iostream>

int main() {
    std::string query;

    while(std::getline(std::cin, query)) {
        std::cout << "NO" << std::endl;
        std::cout.flush();
    }

    return 0;
}