#include <iostream>
#include <fstream>
#include <string>

int main() {
    int id;
    std::string name;
    
    // Input
    std::cin >> id; // Document identifier
    std::cin.ignore(); // Ignore the newline character
    std::getline(std::cin, name); // Name of the document
    
    // Read the text of the document
    std::string line;
    std::string text;
    while (std::getline(std::cin, line)) {
        text += line;
    }
    
    // Check the subject based on the document name or text
    if (name.find("trade") != std::string::npos || text.find("trade") != std::string::npos) {
        std::cout << 3; // Subject is trade
    } else if (name.find("science") != std::string::npos || text.find("science") != std::string::npos) {
        std::cout << 1; // Subject is science
    } else {
        std::cout << 2; // Subject is technology
    }
    
    return 0;
}