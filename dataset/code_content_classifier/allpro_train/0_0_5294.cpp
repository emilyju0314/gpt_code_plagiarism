#include <iostream>

int main() {
    int candies[4];
    for(int i = 0; i < 4; i++) {
        std::cin >> candies[i];
    }
    
    int total = candies[0] + candies[1] + candies[2] + candies[3];
    
    if(total % 2 != 0) {
        std::cout << "NO" << std::endl;
    } else {
        if((candies[0] + candies[1] == total / 2) || 
           (candies[0] + candies[2] == total / 2) ||
           (candies[0] + candies[3] == total / 2) ||
           (candies[1] + candies[2] == total / 2) ||
           (candies[1] + candies[3] == total / 2) ||
           (candies[2] + candies[3] == total / 2)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}