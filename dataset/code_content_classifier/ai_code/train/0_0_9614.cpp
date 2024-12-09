#include <iostream>
#include <cmath>

int main() {
    int D, E;
    
    while (std::cin >> D >> E) {
        if (D == 0 && E == 0) {
            break;
        }
        
        double min_diff = 1e9;
        
        for (int x = 0; x <= D; x++) {
            int y = D - x;
            double rail_cost = sqrt(x * x + y * y);
            min_diff = std::min(min_diff, std::abs(rail_cost - E));
        }
        
        std::cout << min_diff << std::endl;
    }
    
    return 0;
}