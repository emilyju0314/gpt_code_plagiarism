#include <iostream>

void checkNum(int n) {
    for (int i = 1; i <= n; i++) {
        int x = i;
        bool found = false;
        
        while (x != 0) {
            if (x % 10 == 3) {
                std::cout << i << " ";
                found = true;
                break;
            }
            x /= 10;
        }
        
        if (!found && i % 3 == 0) {
            std::cout << i << " ";
        }
    }
    
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    
    checkNum(n);
    
    return 0;
}