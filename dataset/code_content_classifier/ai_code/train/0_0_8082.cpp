#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    
    int sum = 4 * (sqrt((a*b) / c) + sqrt((b*c) / a) + sqrt((c*a) / b));
    
    std::cout << sum << std::endl;
    
    return 0;
}