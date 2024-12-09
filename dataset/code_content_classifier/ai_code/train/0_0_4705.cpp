#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    // Replace all occurrences of "WUB" with a space
    while(input.find("WUB") != std::string::npos) {
        input.replace(input.find("WUB"), 3, " ");
    }

    // Output the resulting string with spaces between each word
    std::string word;
    for(char c : input) {
        if(c == ' ') {
            if(!word.empty()) {
                std::cout << word << " ";
                word.clear();
            }
        } else {
            word += c;
        }
    }
    
    if(!word.empty()) {
        std::cout << word;
    }

    return 0;
}