#include <iostream>

int main() {
    int p, y;
    std::cin >> p >> y;
    
    for(int i = y; i > p; i--) {
        bool suitable = true;
        for(int j = 2; j <= p; j++) {
            if(i % j == 0) {
                suitable = false;
                break;
            }
        }
        if(suitable) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    
    std::cout << "-1" << std::endl;
    
    return 0;
}