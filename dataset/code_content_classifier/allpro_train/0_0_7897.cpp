#include <iostream>
#include <string>
#include <vector>

// Function to reverse the binary notation of a number
unsigned int reverseBinary(unsigned int n) {
    unsigned int result = 0;
    while (n > 0) {
        result <<= 1;
        result |= n & 1;
        n >>= 1;
    }
    return result;
}

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::vector<int> array;
    int prevChar = 0;

    for (char c : text) {
        int ascii = static_cast<int>(c);
        int step1 = reverseBinary(prevChar);
        int step2 = (step1 - ascii) % 256;
        prevChar = reverseBinary(step2);

        array.push_back(prevChar);
    }

    for (int num : array) {
        std::cout << num << std::endl;
    }

    return 0;
}