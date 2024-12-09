#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    for (int k = 1; k < n; k++) {
        if ((k*(k+1)/2) % n == 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    
    return 0;
}