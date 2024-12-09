#include <iostream>

int main() {
    int w, m;
    std::cin >> w >> m;
    
    while (m > 0) {
        bool isPossible = false;
        for (int i = 2; i <= w; i++) {
            if ((m % w == 0) || (m % w == i)) {
                m /= w;
                isPossible = true;
                break;
            }
        }
        if (!isPossible) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    
    return 0;
}