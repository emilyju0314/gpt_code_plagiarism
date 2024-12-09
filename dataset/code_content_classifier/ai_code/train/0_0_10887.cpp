#include <iostream>

int main() {
    int a;
    std::cin >> a;
    
    int result = a + a*a + a*a*a;
    
    std::cout << result << std::endl;
    
    return 0;
}