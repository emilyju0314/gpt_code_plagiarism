#include <iostream>
#include <vector>

int main() {
    int n;
    
    while (true) {
        std::cin >> n;
        
        if (n == 0) {
            break;
        }
        
        std::vector<std::string> movements(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> movements[i];
        }
        
        int count = 0;
        bool onPlatform = false;
        bool onFloor = true;
        
        for (int i = 0; i < n; i++) {
            if (movements[i] == "lu" && onFloor) {
                onFloor = false;
                onPlatform = true;
            } else if (movements[i] == "ru" && onFloor) {
                onFloor = false;
                onPlatform = true;
            } else if (movements[i] == "ld" && onPlatform) {
                onFloor = true;
                onPlatform = false;
                count++;
            } else if (movements[i] == "rd" && onPlatform) {
                onFloor = true;
                onPlatform = false;
                count++;
            }
        }
        
        std::cout << count << std::endl;
    }
    
    return 0;
}