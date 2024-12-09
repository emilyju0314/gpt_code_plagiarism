#include <iostream>
#include <string>

int main() {
    std::string door;
    int rail;
    
    // Input
    std::cin >> door;
    std::cin >> rail;
    
    // Determine if VIP is left-handed or right-handed
    if (door == "front") {
        if (rail == 1) {
            std::cout << "L";
        } else {
            std::cout << "R";
        }
    } else {
        if (rail == 1) {
            std::cout << "R";
        } else {
            std::cout << "L";
        }
    }
    
    return 0;
}