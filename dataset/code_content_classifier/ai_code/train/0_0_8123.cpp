#include <iostream>
#include <string>

int main() {
    char c;
    std::cin >> c;
    
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        std::cout << "vowel" << std::endl;
    } else {
        std::cout << "consonant" << std::endl;
    }
    
    return 0;
}