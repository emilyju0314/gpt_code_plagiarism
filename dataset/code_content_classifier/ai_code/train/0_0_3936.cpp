#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);

    // Find prime numbers less than 30
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    // Fill sequence b
    for (int i = 0; i < n; ++i) {
        int closest_prime = *std::min_element(primes.begin(), primes.end(), [&](int x, int y) {
            return std::abs(x - a[i]) < std::abs(y - a[i]);
        });
        b[i] = closest_prime;
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}