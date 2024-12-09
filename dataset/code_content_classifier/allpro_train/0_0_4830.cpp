#include <iostream>
#include <string>

int main() {
    std::string grid1, grid2;
    std::cin >> grid1 >> grid2;

    std::string rotated_grid2 = std::string(grid2.rbegin(), grid2.rend());

    if (grid1 == rotated_grid2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}