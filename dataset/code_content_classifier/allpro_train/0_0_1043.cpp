#include <iostream>
#include <bitset>

int main() {
    unsigned int x;
    std::cin >> x;
    
    std::bitset<32> b(x);
    std::bitset<32> inversion = ~b;
    std::bitset<32> left_shift = b << 1;
    std::bitset<32> right_shift = b >> 1;

    std::cout << b << std::endl;
    std::cout << inversion << std::endl;
    std::cout << left_shift << std::endl;
    std::cout << right_shift << std::endl;

    return 0;
}