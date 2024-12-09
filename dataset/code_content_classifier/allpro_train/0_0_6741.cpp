#include <iostream>

int main() {
    int n;
    
    while (std::cin >> n) {
        if (n == 0) break;
        
        for (int i = 0; i < n; i++) {
            int a, b;
            int scoreA = 0, scoreB = 0;
            
            for (int j = 0; j < n; j++) {
                std::cin >> a >> b;
                
                if (a > b) {
                    scoreA += a + b;
                } else if (a < b) {
                    scoreB += a + b;
                } else {
                    // Draw, each player takes their own card
                    scoreA += a;
                    scoreB += b;
                }
            }
            
            std::cout << scoreA << " " << scoreB << std::endl;
        }
        
    }
    
    return 0;
}