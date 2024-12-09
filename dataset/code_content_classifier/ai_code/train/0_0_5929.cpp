#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> alcoholDrinks = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    
    int n;
    std::cin >> n;
    
    int additionalChecks = 0;
    
    for (int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;
        
        if (input >= "0" && input <= "1000") { // Check if input is age
            int age = std::stoi(input);
            if (age < 18) {
                additionalChecks++;
            }
        } else {
            if (alcoholDrinks.find(input) != alcoholDrinks.end()) { // Check if input is alcohol drink
                additionalChecks++;
            }
        }
    }
    
    std::cout << additionalChecks << std::endl;
    
    return 0;
} 

// Example input:
// 5
// 18
// VODKA
// COKE
// 19
// 17

// Output:
// 2