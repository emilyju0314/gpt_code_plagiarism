#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int height = 0;
    int total_cubes = 0;
    
    while (total_cubes <= n) {
        height++;
        total_cubes += height * (height + 1) / 2;
    }
    
    std::cout << height - 1 << std::endl;

    return 0;
}