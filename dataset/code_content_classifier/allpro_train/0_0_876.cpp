#include <iostream>

int main() {
    long long x, y, z;
    std::cin >> x >> y >> z;
    
    long long totalCoconuts = (x + y) / z;
    long long leftOverChizhiks = z - (x % z + y % z) % z;
    
    std::cout << totalCoconuts << " " << std::min(leftOverChizhiks, std::min(x % z, y % z)) << std::endl;
    
    return 0;
}