#include <iostream>

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        int h, m;
        std::cin >> h >> m;
        
        int minutes = 0;
        
        if (h == 0) {
            minutes = 60 - m;
        } else {
            minutes += (23 - h) * 60 + (60 - m);
        }
        
        std::cout << minutes << std::endl;
    }
    
    return 0;
}