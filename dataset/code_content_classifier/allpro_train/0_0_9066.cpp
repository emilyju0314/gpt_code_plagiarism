#include <iostream>
#include <cmath>

int main() {
    long long n;
    std::cin >> n;

    int sum = 0;

    while(n > 0) {
        sum = std::max(sum, n % 10);
        n /= 10;
    }

    std::cout << sum << std::endl;

    return 0;
}