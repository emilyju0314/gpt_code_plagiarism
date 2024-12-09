#include <iostream>
#include <string>

int main() {
    std::string input;
    
    while (std::cin >> input) {
        if (input == "0") {
            break;
        }
        
        int sum = 0;
        for (char digit : input) {
            sum += digit - '0';
        }
        
        std::cout << sum << std::endl;
    }
    
    return 0;
}