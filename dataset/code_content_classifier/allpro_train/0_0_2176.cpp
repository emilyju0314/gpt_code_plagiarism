#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    int moves = 0;
    
    while (m % n == 0) {
        if (m / n == 2) {
            n *= 2;
        } else {
            n *= 3;
        }
        moves++;
        
        if (n == m) {
            std::cout << moves << std::endl;
            return 0;
        }
    }
    
    std::cout << -1 << std::endl;
    
    return 0;
}