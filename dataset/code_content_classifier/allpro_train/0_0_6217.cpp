#include <iostream>
#include <cmath>

int main() {
    while (true) {
        int A, B, C, n;
        std::cin >> A >> B >> C;
        
        if (A == 0 && B == 0 && C == 0) {
            break;
        }
        
        std::cin >> n;
        
        for (int i = 0; i < n; i++) {
            int R;
            std::cin >> R;
            
            int diagonal = sqrt(A * A + B * B + C * C);
            
            if (diagonal / 2 > R) {
                std::cout << "OK" << std::endl;
            } else {
                std::cout << "NA" << std::endl;
            }
        }
    }
    
    return 0;
}