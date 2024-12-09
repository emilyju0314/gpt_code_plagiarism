#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;
    
    // Capitalize the first letter
    word[0] = std::toupper(word[0]);
    
    std::cout << word << std::endl;
    
    return 0;
}