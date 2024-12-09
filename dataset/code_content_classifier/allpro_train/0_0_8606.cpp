#include <iostream>

int main() {
    int t, k;
    std::cin >> t >> k;
    
    for(int i=0; i<t; i++) {
        int n, m;
        std::cin >> n >> m;
        
        // Determine the outcome of the game based on the board size
        if(((n-1)/k + (m-1)/k) % 2 == 0) {
            std::cout << "-" << std::endl;
        } else {
            std::cout << "+" << std::endl;
        }
    }
    
    return 0;
}