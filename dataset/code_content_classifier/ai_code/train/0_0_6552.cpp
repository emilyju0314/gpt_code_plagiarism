#include <iostream>
#include <string>

int main() {
    // Query each area of the cat and check its response
    for (int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
        std::cout.flush();

        std::string response;
        std::cin >> response;

        if (response == "grumpy") {
            std::cout << "grumpy" << std::endl;
            return 0;
        }
    }

    std::cout << "normal" << std::endl;

    return 0;
}