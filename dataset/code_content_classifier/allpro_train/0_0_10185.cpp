#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    int lane = (k - 1) / (2 * m) + 1;
    int desk = ((k - 1) / 2) % m + 1;
    char side = (k % 2 == 0) ? 'R' : 'L';
    
    std::cout << lane << " " << desk << " " << side << std::endl;
    
    return 0;
}