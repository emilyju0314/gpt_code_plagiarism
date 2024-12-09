#include <iostream>
#include <cmath>

int main() {
    int x[3], y[3];
    
    for (int i = 0; i < 3; i++) {
        std::cin >> x[i] >> y[i];
    }
    
    if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) {
        std::cout << 1 << std::endl;
    } else if ((x[0] == x[1] && (y[2] < std::min(y[0], y[1]) || y[2] > std::max(y[0], y[1]))) ||
               (x[0] == x[2] && (y[1] < std::min(y[0], y[2]) || y[1] > std::max(y[0], y[2])))) {
        std::cout << 2 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }
    
    return 0;
}