#include <iostream>

int main() {
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    
    if (b/m <= a) {
        std::cout << n*a << std::endl;
    } else {
        int result = (n/m)*b + std::min((n%m)*a, b);
        std::cout << result << std::endl;
    }
    
    return 0;
}