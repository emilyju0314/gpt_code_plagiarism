#include <iostream>

int main() {
    int A, B;
    std::cin >> A >> B;
    
    for (int C = 1; C <= 3; C++) {
        if ((A * B * C) % 2 != 0) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    
    std::cout << "No" << std::endl;
    
    return 0;
}