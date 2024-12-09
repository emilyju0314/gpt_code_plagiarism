#include <iostream>

int main() {
    int total = 0;
    int price;
    
    // Input the prices of 9 books
    for (int i = 0; i < 9; i++) {
        int temp;
        std::cin >> temp;
        total += temp;
    }
    
    // Calculate the price of the book that could not be read
    price = 10000 - total;
    
    std::cout << price << std::endl;
    
    return 0;
}