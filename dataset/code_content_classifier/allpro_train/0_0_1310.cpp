#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    // The minimum number of packets required is equal to the integer square root of 2*n.
    // This is because the triangular numbers are formed by summing consecutive integers,
    // so the highest triangular number that is less than n is the number of packets required. 

    long long packets = std::ceil((std::sqrt(1 + 8*n) - 1) / 2);

    std::cout << packets << std::endl;

    return 0;
}