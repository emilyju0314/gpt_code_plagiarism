#include <iostream>

int main() {
    int n;
    std::cin >> n;
    
    int opinion;
    bool easy = true;
    
    for (int i = 0; i < n; i++) {
        std::cin >> opinion;
        if (opinion == 1) {
            easy = false;
        }
    }
    
    if (easy) {
        std::cout << "EASY" << std::endl;
    } else {
        std::cout << "HARD" << std::endl;
    }
    
    return 0;
}