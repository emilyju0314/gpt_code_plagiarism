#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    if(n % 2 == 0) {
        std::cout << 0 << std::endl; // if input is even, output 0
    } else {
        std::cout << 1 << std::endl; // if input is odd, output 1
    }
    
    return 0;
}