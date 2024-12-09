#include <iostream>

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;
    
    long long area = n * m;
    
    if (area % k != 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        
        long long common_divisor = area / k;
        
        long long x1 = 0, y1 = 0;
        long long x2 = 0, y2 = m;
        long long x3 = common_divisor / m, y3 = 0;
        
        std::cout << x1 << " " << y1 << std::endl;
        std::cout << x2 << " " << y2 << std::endl;
        std::cout << x3 << " " << y3 << std::endl;
    }
    
    return 0;
}