#include <iostream>
#include <fstream>
#include <string>

int main() {
    int id;
    std::string docName, text;
    
    // Read input from user
    std::cin >> id;
    std::cin.ignore(); // Ignore newline character
    std::getline(std::cin, docName);
    while (std::getline(std::cin, text)) {
        // Process text if needed
    }
    
    // Check the subject based on the document content or any other criteria
    int subject;
    // Your logic to determine the subject
    
    // Print the subject
    std::cout << subject << std::endl;

    return 0;
}