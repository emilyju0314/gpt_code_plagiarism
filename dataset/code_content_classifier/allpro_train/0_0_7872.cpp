#include <iostream>
#include <cmath>

int main() {
    int a, b;
    
    while (true) {
        std::cin >> a >> b;
        
        if (a == 0 && b == 0) {
            break;
        }
        
        int a1, a2, b1, b2;
        int minSum = INT_MAX;
        
        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                a1 = i;
                a2 = a / i;
                
                for (int j = 1; j <= b; j++) {
                    if (b % j == 0) {
                        b1 = j;
                        b2 = b / j;
                        
                        int sum = pow(a2 - a1, 2) + pow(b2 - b1, 2);
                        minSum = std::min(minSum, sum);
                    }
                }
            }
        }
        
        std::cout << minSum << std::endl;
    }
    
    return 0;
}