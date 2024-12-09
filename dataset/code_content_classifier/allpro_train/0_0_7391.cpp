#include <iostream>

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    // Case 1: If m is less than or equal to k
    if (m <= k) {
        std::cout << m << std::endl;
    } 
    // Case 2: If m is greater than k but less than or equal to n - k
    else if (m <= n - k) {
        std::cout << k << std::endl;
    } 
    // Case 3: If m is greater than n - k
    else {
        std::cout << (m - (n - k)) << std::endl;
    }

    return 0;
}