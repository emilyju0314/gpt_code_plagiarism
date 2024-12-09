#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> powers(n);
    for(int i = 0; i < n; i++) {
        std::cin >> powers[i];
    }
    
    std::sort(powers.begin(), powers.end());
    
    int minPower = powers[0] + powers[n-1];
    
    std::cout << minPower << std::endl;
    
    return 0;
}