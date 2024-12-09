#include <iostream>

int main() {
    int n, x;
    std::cin >> n >> x;
    
    int a, b;
    std::cin >> a >> b;
    
    std::cout << (a+x-1)/x << " " << (b+x-1)/x << std::endl;
    
    return 0;
}