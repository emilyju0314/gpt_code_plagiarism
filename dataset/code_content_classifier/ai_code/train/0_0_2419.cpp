#include <iostream>

int main() {
    while (true) {
        int n, p;
        std::cin >> n >> p;
        
        if (n == 0 && p == 0) {
            break;
        }
        
        int candidate = 0;
        while (p > 0) {
            // Take one pebble
            p--;
            
            // Pass the bowl to the next candidate
            candidate = (candidate + 1) % n;
            
            // If it's the last pebble, the current candidate wins
            if (p == 0) {
                std::cout << candidate << std::endl;
            }
        }
    }
    
    return 0;
}