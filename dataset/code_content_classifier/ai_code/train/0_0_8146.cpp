#include <iostream>

int main() {
    std::string input;

    while (true) {
        std::cin >> input;
        
        if (input == "end") {
            break;
        } else if (input == "start") {
            std::cout << "? 0 0" << std::endl;
            std::flush(std::cout);

            std::cin >> input;
            if (input == "x") {
                std::cout << "! 1" << std::endl;
                std::flush(std::cout);
            } else if (input == "mistake") {
                return 0;
            }
        }
    }

    return 0;
}