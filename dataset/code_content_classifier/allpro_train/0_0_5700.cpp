#include <iostream>

int main() {
    int d;
    
    while (std::cin >> d) {
        int area = 0;
        for (int i = d; i <= 600 - d; i += d) {
            area += d * i * i;
        }
        
        std::cout << area << std::endl;
    }
    
    return 0;
}