#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string text;
    std::getline(std::cin, text);
    
    for (int i = 0; i < text.length(); i++) {
        if (islower(text[i])) {
            text[i] = toupper(text[i]);
        }
    }
    
    std::cout << text << std::endl;
    
    return 0;
}