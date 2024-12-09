#include <iostream>
#include <string>

std::string performOperation(const std::string& input) {
    std::string result;
    char current = input[0];
    int count = 1;
    
    for (int i = 1; i < input.length(); i++) {
        if (input[i] == current) {
            count++;
        } else {
            result += std::to_string(count) + current;
            current = input[i];
            count = 1;
        }
    }
    
    result += std::to_string(count) + current;
    
    return result;
}

int main() {
    int n;
    std::string input;
    
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        
        std::cin >> input;
        
        for (int i = 0; i < n; i++) {
            input = performOperation(input);
        }
        
        std::cout << input << std::endl;
    }
    
    return 0;
}