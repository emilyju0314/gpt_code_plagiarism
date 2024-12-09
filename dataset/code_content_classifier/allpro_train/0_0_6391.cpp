#include <iostream>
#include <string>

int main() {
    std::string input;
    
    while (std::cin >> input) {
        while (input.size() > 1) {
            std::string result;
            for (int i = 0; i < input.size() - 1; i++) {
                int num1 = input[i] - '0';
                int num2 = input[i + 1] - '0';
                int sum = (num1 + num2) % 10;
                result += std::to_string(sum);
            }
            input = result;
        }
        
        std::cout << input << std::endl;
    }
    
    return 0;
}