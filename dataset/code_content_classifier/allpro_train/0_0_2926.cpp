#include <iostream>
#include <iomanip>

int main() {
    int testCases = 0;
    double a = 0.0;
    
    std::cin >> testCases;
    
    for(int i = 0; i < testCases; i++) {
        std::cin >> a;
        
        double sum = a;
        double currentTerm = a;
        
        for(int j = 2; j <= 10; j++) {
            if(j % 2 == 0) {
                currentTerm *= 2.0;
            } else {
                currentTerm /= 3.0;
            }
            
            sum += currentTerm;
        }
        
        std::cout << std::fixed << std::setprecision(8) << sum << std::endl;
    }
    
    return 0;
}