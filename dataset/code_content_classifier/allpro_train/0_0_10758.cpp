#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> radii(n);
    for(int i = 0; i < n; i++) {
        std::cin >> radii[i];
    }
    
    std::sort(radii.begin(), radii.end(), std::greater<int>());
    
    int snowmen = 0;
    std::vector<std::vector<int>> snowmenRadii;
    for(int i = 0; i < n-2; i++) {
        if(radii[i] < radii[i+1] + radii[i+2]) {
            snowmen++;
            snowmenRadii.push_back({radii[i], radii[i+1], radii[i+2]});
            i += 2;
        }
    }
    
    std::cout << snowmen << std::endl;
    for(auto snowman : snowmenRadii) {
        for(int radius : snowman) {
            std::cout << radius << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}