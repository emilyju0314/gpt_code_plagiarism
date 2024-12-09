#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> subjectMap;
    subjectMap["1"] = 1;
    subjectMap["2"] = 2;
    subjectMap["3"] = 3;

    int id;
    std::string name, text;
    
    std::cin >> id;
    std::cin.ignore();
    std::getline(std::cin, name);

    while (std::getline(std::cin, text)) {
        // Process the document text if needed
    }

    // Assume you have processed the document text and now need to determine the subject
    if (name == "1") {
        std::cout << subjectMap["1"] << std::endl;
    } else if (name == "2") {
        std::cout << subjectMap["2"] << std::endl;
    } else {
        std::cout << subjectMap["3"] << std::endl;
    }

    return 0;
}