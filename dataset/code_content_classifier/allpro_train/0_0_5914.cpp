#include <iostream>
#include <fstream>
#include <string>

int main() {
    int id;
    std::string name, text;

    // Input id, name, and text of the document
    std::cin >> id;
    std::cin.ignore(); // Ignore newline character
    std::getline(std::cin, name);

    while(std::getline(std::cin, text)) {
        // Process text of the document
        // You can analyze the text to determine the subject

        // For this example, let's assume the subject is based on the length of the text
        int subject;
        if(text.length() < 1000) {
            subject = 1;
        } else if(text.length() < 5000) {
            subject = 2;
        } else {
            subject = 3;
        }

        // Output the determined subject
        std::cout << subject << std::endl;
        break; // Exit after determining the subject for the first line of text
    }

    return 0;
} 

// This is a basic example that assumes the subject is determined based on the length of the text. You can modify the logic to analyze the actual content of the text if needed.