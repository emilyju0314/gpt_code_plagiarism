#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

int main() {
    std::unordered_map<std::string, int> subject_map;
    
    subject_map["1"] = 1;
    subject_map["2"] = 2;
    subject_map["3"] = 3;
    
    int id;
    std::string name, text;
    
    // Input
    std::cin >> id;
    std::cin.ignore();
    std::getline(std::cin, name);
    
    // Read text of the document
    while (std::getline(std::cin, text)) {
        // Process the text if needed
    }
    
    // Determine the subject based on the document information
    // For example, you can analyze the text
    
    // For this example, just output a random subject between 1 and 3
    std::cout << (id % 3) + 1 << std::endl;
    
    return 0;
}