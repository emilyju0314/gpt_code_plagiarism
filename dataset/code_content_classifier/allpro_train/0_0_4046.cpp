#include <iostream>
#include <algorithm>

int main() {
    long long H, W;
    std::cin >> H >> W;
    
    // Total reachable squares are the sum of diagonals starting from (1,1) and (H,W)
    long long total_reachable = std::min(H, W);
    
    // If the board is a rectangle shape, then the reachable squares are doubled
    if (H > 1 && W > 1) {
        total_reachable += (std::min(H, W) - 1) * 2;
    }
    
    std::cout << total_reachable << std::endl;
    
    return 0;
}