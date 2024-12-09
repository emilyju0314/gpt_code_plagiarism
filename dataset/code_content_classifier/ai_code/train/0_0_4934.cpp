#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    
    while (true) {
        std::cin >> n;
        if (n == 0) {
            break;
        }
        
        std::vector<int> scores(n);
        
        double average = 0.0;
        
        // Calculate the average
        for (int i = 0; i < n; i++) {
            std::cin >> scores[i];
            average += scores[i];
        }
        
        average /= n;
        
        // Calculate the variance
        double variance = 0.0;
        for (int i = 0; i < n; i++) {
            variance += pow(scores[i] - average, 2);
        }
        variance /= n;
        
        // Calculate the standard deviation
        double standard_deviation = sqrt(variance);
        
        std::cout << std::fixed;
        std::cout.precision(8);
        std::cout << standard_deviation << std::endl;
    }
    
    return 0;
}