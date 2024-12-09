#include <iostream>

int main() {
    int n;
    
    while(std::cin >> n) {
        // Calculate the maximum number of regions
        int max_regions = n * n + n + 2;
        
        // Output the result for the current dataset
        std::cout << max_regions << std::endl;
    }
    
    return 0;
}