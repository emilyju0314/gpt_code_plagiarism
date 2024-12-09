#include <iostream>
#include <cmath>

int main() {
    int X;
    std::cin >> X;
    
    int time = ceil((-1 + sqrt(1 + 8*X)) / 2);
    
    std::cout << time << std::endl;
    
    return 0;
}