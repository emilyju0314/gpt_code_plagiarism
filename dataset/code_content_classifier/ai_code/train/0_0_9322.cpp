#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string firstLayout, secondLayout, text;
    std::unordered_map<char, char> layoutMapping;

    // Read input
    std::cin >> firstLayout >> secondLayout >> text;
    
    // Create mapping between first and second layouts
    for (int i = 0; i < 26; ++i) {
        layoutMapping[firstLayout[i]] = secondLayout[i];
    }

    // Replace characters in the text with corresponding characters from the second layout
    for (char &c : text) {
        if (isalpha(c)) {
            c = layoutMapping[tolower(c)];
            if (isupper(text[&c - &text[0]])) {
                c = toupper(c);
            }
        }
    }

    // Print the modified text
    std::cout << text << std::endl;

    return 0;
}