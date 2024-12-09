#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string red, green, bottom;
    
    while (true) {
        std::cin >> red;
        if (red == "-") {
            break;
        }
        std::cin >> green;
        std::cin >> bottom;
        
        for (char c : red) {
            if (bottom.find(c) == std::string::npos && green.find(tolower(c)) == std::string::npos) {
                std::cout << c;
            }
        }
        for (char c : bottom) {
            if (green.find(c) == std::string::npos && red.find(toupper(c)) == std::string::npos) {
                std::cout << c;
            }
        }
        for (char c : green) {
            if (bottom.find(c) == std::string::npos && red.find(toupper(c)) == std::string::npos) {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}