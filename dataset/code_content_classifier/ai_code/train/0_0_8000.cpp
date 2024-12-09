#include <iostream>
#include <string>

int main() {
    std::string line;
    std::cin >> line;
    
    int boys = 0;
    int girls = 0;
    int swaps = 0;
    
    for (char c : line) {
        if (c == 'M') {
            boys++;
        } else {
            swaps += boys;
        }
    }
    
    std::cout << swaps << std::endl;
    
    return 0;
}