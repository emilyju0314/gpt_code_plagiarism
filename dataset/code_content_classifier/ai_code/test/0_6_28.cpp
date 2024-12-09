#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        
        int sum = a + b + c;
        
        if (sum % 2 == 0) {
            std::cout << std::abs((a * 1 + b * 2) - (c * 3)) << std::endl;
        } else {
            std::cout << std::abs(((a - 1) * 1 + b * 2) - (c * 3)) << std::endl;
        }
    }

    return 0;
}