#include <iostream>
#include <bitset>

int main() {
    unsigned int a, b;
    std::cin >> a >> b;

    unsigned int AND_result = a & b;
    unsigned int OR_result = a | b;
    unsigned int XOR_result = a ^ b;

    std::cout << std::bitset<32>(AND_result) << std::endl;
    std::cout << std::bitset<32>(OR_result) << std::endl;
    std::cout << std::bitset<32>(XOR_result) << std::endl;

    return 0;
}