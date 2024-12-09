#include <iostream>
#include <cmath>

void drawRhombus(int n) {
    int size = n * 2 - 1;
    
    for (int i = 1 - n; i <= n - 1; i++) {
        int spaces = n - 1 - abs(i);
        
        // Adding spaces
        for (int j = 0; j < spaces; j++) {
            std::cout << "  ";
        }
        
        // Adding numbers
        for (int j = 0; j < n - abs(i); j++) {
            std::cout << j << " ";
        }
        
        for (int j = n - abs(i) - 2; j >= 0; j--) {
            std::cout << j;
            
            if (j != 0) {
                std::cout << " ";
            }
        }
        
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    
    drawRhombus(n);
    
    return 0;
}