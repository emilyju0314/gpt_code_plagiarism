#include <iostream>

int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    int x3 = x1 - dy;
    int y3 = y1 + dx;
    int x4 = x2 - dy;
    int y4 = y2 + dx;
    
    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    
    return 0;
}