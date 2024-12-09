#include <iostream>

int main() {
    int n, k, t;
    std::cin >> n >> k >> t;
    
    int totalSaturation = n * k;
    int targetSaturation = totalSaturation * t / 100;
    
    for (int i = 1; i <= n; ++i) {
        int saturation = std::min(k, targetSaturation);
        targetSaturation -= saturation;
        std::cout << saturation << " ";
    }
    
    return 0;
}