#include <iostream>
#include <string>

int main() {
    std::string input;
    
    while (std::cin >> input) {
        int countJOI = 0;
        int countIOI = 0;
        
        for (int i = 0; i < input.size() - 2; ++i) {
            if (input[i] == 'J' && input[i + 1] == 'O' && input[i + 2] == 'I') {
                countJOI++;
            }
            if (input[i] == 'I' && input[i + 1] == 'O' && input[i + 2] == 'I') {
                countIOI++;
            }
        }
        
        std::cout << countJOI << std::endl;
        std::cout << countIOI << std::endl;
    }
    
    return 0;
}