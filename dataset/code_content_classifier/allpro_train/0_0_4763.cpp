#include <iostream>

int findMinCoins(int n) {
    int coins[] = {25, 10, 5, 1};
    int numCoins = 0;
    
    for(int i=0; i<4; i++) {
        numCoins += n / coins[i];
        n %= coins[i];
    }
    
    return numCoins;
}

int main() {
    int n;
    std::cin >> n;
    
    std::cout << findMinCoins(n) << std::endl;
    
    return 0;
}