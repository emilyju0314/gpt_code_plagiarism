#include <iostream>
#include <cmath>

int main() {
    long long X;
    std::cin >> X;
    
    long long balance = 100;
    int years = 0;
    
    while(balance < X) {
        balance += balance / 100;
        years++;
    }
    
    std::cout << years << std::endl;
    
    return 0;
}