#include <iostream>

int main() {
    int a, b, c, d;
    int e, f, g, h;
    
    std::cin >> a >> b >> c >> d;
    std::cin >> e >> f >> g >> h;
    
    int average = (a + b + c + d + e + f + g + h) / 8;
    std::cout << average << std::endl;
    
    if (b > average) {
        std::cout << "2" << std::endl;
    }
    if (c > average) {
        std::cout << "3" << std::endl;
    }
    
    return 0;
}