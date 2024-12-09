#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, l, r;
        std::cin >> n >> l >> r;
        
        if (n < l) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes" << std::endl;
        }
    }
    
    return 0;
}