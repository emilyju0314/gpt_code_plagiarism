#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // Create a mapping of document identifiers to subjects
    std::unordered_map<int, int> documentSubjects = {
        {0, 1},
        {1, 2},
        {2, 3}
        // Add more mappings if needed
    };
    
    // Read the document identifier
    int id;
    std::cin >> id;
    
    // Read and discard the document name
    std::string name;
    std::getline(std::cin, name); // Read and discard the newline character
    
    // Keep reading and discarding text until the end of the document
    std::string line;
    while(std::getline(std::cin, line)) {
        // Stop reading when an empty line is encountered
        if(line.empty()) {
            break;
        }
    }
    
    // Output the subject number corresponding to the given document identifier
    std::cout << documentSubjects[id] << std::endl;

    return 0;
}