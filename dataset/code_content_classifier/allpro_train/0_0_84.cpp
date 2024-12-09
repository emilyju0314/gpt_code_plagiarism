#include <iostream>
#include <cmath>

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    int diff_x = x2 - x1;
    int diff_y = y2 - y1;
    
    if ((diff_x == 0 && diff_y == 0) || 
        (diff_x == x3 && diff_y == y3) || 
        (diff_y == x3 && -diff_x == y3) || 
        (-diff_x == x3 && -diff_y == y3) || 
        (-diff_y == x3 && diff_x == y3)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}