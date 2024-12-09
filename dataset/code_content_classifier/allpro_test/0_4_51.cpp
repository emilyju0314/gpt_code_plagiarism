#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long n;
        std::cin >> n;

        long long l = (-1 + std::sqrt(1 + 8 * n)) / 2;
        long long sum = l * (l + 1) / 2;

        long long r = n - sum;

        std::cout << r << " " << r + l << std::endl;
    }

    return 0;
}