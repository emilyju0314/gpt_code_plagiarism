#include <iostream>

int main() {
    char a, b;
    std::cin >> a >> b;
    
    if (a == 'H') {
        if (b == 'H') {
            std::cout << "H";
        } else {
            std::cout << "D";
        }
    } else {
        if (b == 'H') {
            std::cout << "D";
        } else {
            std::cout << "H";
        }
    }
    
    return 0;
}