#include <iostream>
#include <string>

int main() {
    std::string input;
    std::getline(std::cin, input);

    bool inQuotes = false;
    std::string currentLexeme;
    for (char c : input) {
        if (c == ' ' && !inQuotes) {
            if (!currentLexeme.empty()) {
                std::cout << "<" << currentLexeme << ">" << std::endl;
                currentLexeme.clear();
            }
        } else if (c == '"') {
            if (inQuotes) {
                std::cout << "<" << currentLexeme << ">" << std::endl;
                currentLexeme.clear();
                inQuotes = false;
            } else {
                inQuotes = true;
            }
        } else {
            currentLexeme += c;
        }
    }
    
    if (!currentLexeme.empty()) {
        std::cout << "<" << currentLexeme << ">" << std::endl;
    }

    return 0;
}