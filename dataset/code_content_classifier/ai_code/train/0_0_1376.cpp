#include <iostream>
#include <vector>

int main() {
    int leftWeight;
    
    while (std::cin >> leftWeight) {
        if (leftWeight == 0) {
            break;
        }
        
        std::vector<int> weights = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        std::vector<int> rightPlate;
        
        for (int i = weights.size() - 1; i >= 0; i--) {
            if (leftWeight >= weights[i]) {
                leftWeight -= weights[i];
                rightPlate.push_back(weights[i]);
            }
        }
        
        for (int i = 0; i < rightPlate.size(); i++) {
            if (i > 0) {
                std::cout << " ";
            }
            std::cout << rightPlate[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}