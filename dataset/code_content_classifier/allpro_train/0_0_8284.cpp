#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cin >> input;

    int count = 0;
    if (input.find("Danil") != std::string::npos) {
        count++;
    }
    if (input.find("Olya") != std::string::npos) {
        count++;
    }
    if (input.find("Slava") != std::string::npos) {
        count++;
    }
    if (input.find("Ann") != std::string::npos) {
        count++;
    }
    if (input.find("Nikita") != std::string::npos) {
        count++;
    }

    if (count == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}