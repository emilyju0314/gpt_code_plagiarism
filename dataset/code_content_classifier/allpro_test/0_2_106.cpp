#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;
        
        for (int j = 0; j < n; ++j) {
            std::cout << 111;
            if (j != n-1) {
                std::cout << " ";
            }
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}