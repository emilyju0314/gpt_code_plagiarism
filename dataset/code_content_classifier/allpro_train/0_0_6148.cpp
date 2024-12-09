#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    if (n % 3 == 0) {
        std::cout << "1 1 " << n-2 << std::endl;
    } else if ((n-1) % 3 == 0) {
        std::cout << "1 1 " << n-2 << std::endl;
    } else {
        std::cout << "1 2 " << n-3 << std::endl;
    }
    
    return 0;
}