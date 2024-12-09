#include <iostream>
#include <string>

int main() {
    std::string hexNumber;
    std::cin >> hexNumber;
    
    int lastDigit = hexNumber[6] - '0';
    
    if (lastDigit % 2 == 0) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 1 << std::endl;
    }
    
    return 0;
}