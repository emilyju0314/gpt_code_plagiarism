#include <iostream>
#include <string>

int main() {
    std::string input;

    while (std::getline(std::cin, input)) {
        if (input == "#") {
            break;
        }

        int violations = 0;
        char prev = '\0'; // Initialize previous arrow direction to null

        for (char arrow : input) {
            if (arrow == '5') { // Skip arrow direction 5
                continue;
            }

            if (prev == '\0') { // Set initial arrow direction
                prev = arrow;
            } else if ((prev == '1' || prev == '8') && (arrow == '2' || arrow == '9')) { // Check left and right foot constraints
                // Violation detected
                violations++;
                prev = arrow; // Set new arrow direction
            } else if ((prev == '2' || prev == '9') && (arrow == '1' || arrow == '8')) { // Check left and right foot constraints
                // Violation detected
                violations++;
                prev = arrow; // Set new arrow direction
            } else {
                prev = arrow; // Set new arrow direction
            }
        }

        std::cout << violations << std::endl; // Output the number of violations for this dataset
    }

    return 0;
}