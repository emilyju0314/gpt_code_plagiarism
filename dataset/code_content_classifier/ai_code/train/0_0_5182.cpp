#include <iostream>

int main() {
    int amount;
    
    while(std::cin >> amount && amount != 0) {
        int coins = 0;
        
        coins += amount / 500;
        amount %= 500;
        
        coins += amount / 100;
        amount %= 100;
        
        coins += amount / 50;
        amount %= 50;
        
        coins += amount / 10;
        amount %= 10;
        
        coins += amount / 5;
        amount %= 5;
        
        coins += amount;
        
        std::cout << coins << std::endl;
    }
    
    return 0;
}