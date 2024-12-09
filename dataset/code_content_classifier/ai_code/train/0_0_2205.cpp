#include <iostream>

int main() {
    int a1, b1, a2, b2, a3, b3, a4, b4;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;

    if ((std::max(a1, b1) < std::min(a3, b3) && std::max(a2, b2) < std::min(a4, b4)) || 
        (std::max(a1, b1) < std::min(a4, b4) && std::max(a2, b2) < std::min(a3, b3))) {
        std::cout << "Team 1" << std::endl;
    } else if ((std::max(a3, b3) < std::min(a1, b1) && std::max(a4, b4) < std::min(a2, b2)) || 
               (std::max(a3, b3) < std::min(a2, b2) && std::max(a4, b4) < std::min(a1, b1))) {
        std::cout << "Team 2" << std::endl;
    } else {
        std::cout << "Draw" << std::endl;
    }

    return 0;
}