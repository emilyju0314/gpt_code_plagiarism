#include <iostream>

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }
        
        int totalHits = 0;
        
        for (int i = 0; i < n / 4; i++) {
            for (int j = 0; j < 4; j++) {
                int hits;
                std::cin >> hits;
                totalHits += hits;
            }
        }
        
        std::cout << totalHits << std::endl;
    }
    
    return 0;
}