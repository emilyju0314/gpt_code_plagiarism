#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << (n * 4) << std::endl;
    }
    
    return 0;
}