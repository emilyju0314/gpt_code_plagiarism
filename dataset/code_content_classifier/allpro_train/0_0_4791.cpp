#include <iostream>
#include <cmath>

int main() {
    int n, m;
    std::cin >> n >> m;

    long long result = 0;
    
    // Calculate the result using the formula (2^n - 1)%m
    result = (pow(2, n) - 1) % m;

    std::cout << result << std::endl;

    return 0;
}